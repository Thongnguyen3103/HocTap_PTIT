import argparse
import json
import socket
import threading
import webbrowser
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from typing import Any
from urllib.parse import urlparse


BASE_DIR = Path(__file__).resolve().parent
DATA_FILE = BASE_DIR / "grade_tracker_data.json"
HTML_FILE = BASE_DIR / "grade_tracker_web.html"

DEFAULT_WEIGHTS = {
    "attendanceWeight": 10,
    "assignmentWeight": 20,
    "midtermWeight": 20,
    "finalWeight": 50,
}

DEFAULT_META = {
    "studentName": "",
    "targetKha": 7.0,
    "targetGioi": 8.0,
}

SUBJECTS = [
    {"order": 1, "name": "Nhập môn Internet và eLearning", "code": "INT11176", "credits": 2, "semester": "HK1"},
    {"order": 2, "name": "Triết học Mác-Lênin", "code": "BAS1150", "credits": 3, "semester": "HK1"},
    {"order": 3, "name": "Đại số", "code": "BAS1201", "credits": 3, "semester": "HK1"},
    {"order": 4, "name": "Giải tích 1", "code": "BAS1203", "credits": 3, "semester": "HK1"},
    {"order": 5, "name": "Tin học cơ sở 1", "code": "INT1154", "credits": 2, "semester": "HK1"},
    {"order": 6, "name": "Kinh tế chính trị Mác-Lênin", "code": "BAS1151", "credits": 2, "semester": "HK1"},
    {"order": 7, "name": "Vật lý 1 và thí nghiệm", "code": "BAS1224", "credits": 4, "semester": "HK1"},
    {"order": 8, "name": "Kỹ năng tạo lập văn bản", "code": "SKD1103", "credits": 1, "semester": "HK1"},
    {"order": 9, "name": "Xác suất thống kê", "code": "BAS1226", "credits": 2, "semester": "HK2"},
    {"order": 10, "name": "Tiếng Anh A11", "code": "BAS1141", "credits": 3, "semester": "HK2"},
    {"order": 11, "name": "Giải tích 2", "code": "BAS1204", "credits": 3, "semester": "HK2"},
    {"order": 12, "name": "Tin học cơ sở 2", "code": "INT1155", "credits": 2, "semester": "HK2"},
    {"order": 13, "name": "Kỹ thuật số", "code": "ELE1433", "credits": 2, "semester": "HK2"},
    {"order": 14, "name": "Chủ nghĩa xã hội khoa học", "code": "BAS1152", "credits": 2, "semester": "HK2"},
    {"order": 15, "name": "Xử lý tín hiệu số", "code": "ELE1330", "credits": 2, "semester": "HK2"},
    {"order": 16, "name": "Vật lý 3 và thí nghiệm", "code": "BAS1227", "credits": 4, "semester": "HK2"},
    {"order": 17, "name": "Tiếng Anh A12", "code": "BAS1142", "credits": 4, "semester": "HK3"},
    {"order": 18, "name": "Toán rời rạc 1", "code": "INT1358", "credits": 3, "semester": "HK3"},
    {"order": 19, "name": "Ngôn ngữ lập trình C++", "code": "INT1339", "credits": 3, "semester": "HK3"},
    {"order": 20, "name": "Tư tưởng Hồ Chí Minh", "code": "BAS1122", "credits": 2, "semester": "HK3"},
    {"order": 21, "name": "Lý thuyết thông tin", "code": "ELE1319", "credits": 3, "semester": "HK3"},
    {"order": 22, "name": "Kiến trúc máy tính", "code": "INT13145", "credits": 3, "semester": "HK3"},
    {"order": 23, "name": "Kỹ năng làm việc nhóm", "code": "SKD1102", "credits": 1, "semester": "HK3"},
    {"order": 24, "name": "Tiếng Anh A21", "code": "BAS1143", "credits": 3, "semester": "HK4"},
    {"order": 25, "name": "Toán rời rạc 2", "code": "INT1359", "credits": 3, "semester": "HK4"},
    {"order": 26, "name": "Cấu trúc dữ liệu và giải thuật", "code": "INT1306", "credits": 3, "semester": "HK4"},
    {"order": 27, "name": "Lịch sử Đảng Cộng sản Việt Nam", "code": "BAS1153", "credits": 2, "semester": "HK4"},
    {"order": 28, "name": "Lập trình hướng đối tượng", "code": "INT1332", "credits": 3, "semester": "HK4"},
    {"order": 29, "name": "Cơ sở dữ liệu", "code": "INT1313", "credits": 3, "semester": "HK4"},
    {"order": 30, "name": "Hệ điều hành", "code": "INT1319", "credits": 3, "semester": "HK4"},
    {"order": 31, "name": "Tiếng Anh A22", "code": "BAS1144", "credits": 4, "semester": "HK5"},
    {"order": 32, "name": "Mạng máy tính", "code": "INT1336", "credits": 3, "semester": "HK5"},
    {"order": 33, "name": "Lập trình với Python", "code": "INT13162", "credits": 3, "semester": "HK5"},
    {"order": 34, "name": "Nhập môn trí tuệ nhân tạo", "code": "INT1341", "credits": 3, "semester": "HK5"},
    {"order": 35, "name": "Nhập môn công nghệ phần mềm", "code": "INT1340", "credits": 3, "semester": "HK5"},
    {"order": 36, "name": "An toàn và bảo mật hệ thống thông tin", "code": "INT1303", "credits": 3, "semester": "HK5"},
    {"order": 37, "name": "Kỹ năng thuyết trình", "code": "SKD1101", "credits": 1, "semester": "HK5"},
    {"order": 38, "name": "Lập trình web", "code": "INT1434", "credits": 3, "semester": "HK6"},
    {"order": 39, "name": "Cơ sở dữ liệu phân tán", "code": "INT14148", "credits": 3, "semester": "HK6"},
    {"order": 40, "name": "Thực tập cơ sở", "code": "INT13147", "credits": 3, "semester": "HK6"},
    {"order": 41, "name": "Phương pháp luận NCKH", "code": "SKD1108", "credits": 2, "semester": "HK6"},
    {"order": 42, "name": "Xử lý ảnh", "code": "INT13146", "credits": 3, "semester": "HK6"},
    {"order": 43, "name": "IoT và ứng dụng", "code": "INT14149", "credits": 3, "semester": "HK6"},
    {"order": 44, "name": "Quản lý dự án phần mềm", "code": "INT1450", "credits": 2, "semester": "HK6"},
    {"order": 45, "name": "Phân tích và thiết kế HTTT", "code": "INT1342", "credits": 3, "semester": "HK7"},
    {
        "order": 46,
        "name": "Học phần tự chọn HK7",
        "code": "INT1421",
        "credits": 3,
        "semester": "HK7",
        "editable": True,
        "hint": "Gợi ý từ ảnh: Hệ trợ giúp quyết định (INT1421)",
    },
    {"order": 47, "name": "Nhập môn khoa học dữ liệu", "code": "INT14150", "credits": 3, "semester": "HK7"},
    {"order": 48, "name": "Phát triển hệ thống thông tin quản lý", "code": "INT1445", "credits": 3, "semester": "HK7"},
    {"order": 49, "name": "Kho dữ liệu và khai phá dữ liệu", "code": "INT1422", "credits": 3, "semester": "HK7"},
    {"order": 50, "name": "Phát triển hệ thống thương mại điện tử", "code": "INT1446", "credits": 3, "semester": "HK7"},
    {"order": 51, "name": "Hệ cơ sở dữ liệu đa phương tiện", "code": "INT1418", "credits": 3, "semester": "HK8"},
    {"order": 52, "name": "Các hệ thống phân tán", "code": "INT1405", "credits": 3, "semester": "HK8"},
    {"order": 53, "name": "Chuyên đề hệ thống thông tin", "code": "INT1409", "credits": 1, "semester": "HK8"},
    {"order": 54, "name": "Thực tập và tốt nghiệp", "code": "TN-HK9", "credits": 12, "semester": "HK9"},
]

HTML_TEMPLATE = ""


def default_state() -> dict[str, Any]:
    return {
        "meta": {**dict(DEFAULT_META), "openSemester": "HK1", "openSubject": "", "activeView": "dashboard"},
        "scores": {
            subject["code"]: {
                "attendance": "",
                "assignment": "",
                "midterm": "",
                "finalExam": "",
                **DEFAULT_WEIGHTS,
                "customName": subject["name"] if subject.get("editable") else "",
                "customCode": subject["code"] if subject.get("editable") else "",
                "actualSemester": subject["semester"],
                "passStatus": "",
            }
            for subject in SUBJECTS
        },
    }


def load_state() -> dict[str, Any]:
    if not DATA_FILE.exists():
        return default_state()

    try:
        raw = json.loads(DATA_FILE.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return default_state()

    state = default_state()
    if isinstance(raw, dict):
        meta = raw.get("meta")
        if isinstance(meta, dict):
            state["meta"].update(meta)

        scores = raw.get("scores")
        if isinstance(scores, dict):
            for code, values in scores.items():
                if code in state["scores"] and isinstance(values, dict):
                    state["scores"][code].update(values)
    return state


def save_state(payload: dict[str, Any]) -> None:
    state = default_state()
    if isinstance(payload, dict):
        meta = payload.get("meta")
        if isinstance(meta, dict):
            state["meta"].update(meta)

        scores = payload.get("scores")
        if isinstance(scores, dict):
            for code, values in scores.items():
                if code in state["scores"] and isinstance(values, dict):
                    state["scores"][code].update(values)

    DATA_FILE.write_text(json.dumps(state, ensure_ascii=False, indent=2), encoding="utf-8")


def render_html() -> bytes:
    html = HTML_FILE.read_text(encoding="utf-8")
    html = html.replace("__SUBJECTS__", json.dumps(SUBJECTS, ensure_ascii=False))
    html = html.replace("__DEFAULT_WEIGHTS__", json.dumps(DEFAULT_WEIGHTS, ensure_ascii=False))
    html = html.replace("__DEFAULT_META__", json.dumps(DEFAULT_META, ensure_ascii=False))
    html = html.replace("__INITIAL_STATE__", json.dumps(load_state(), ensure_ascii=False))
    return html.encode("utf-8")


class GradeTrackerHandler(BaseHTTPRequestHandler):
    def do_GET(self) -> None:
        path = urlparse(self.path).path
        if path in {"/", "/index.html"}:
            self._send_response(200, render_html(), "text/html; charset=utf-8")
            return

        if path == "/api/data":
            payload = json.dumps(load_state(), ensure_ascii=False).encode("utf-8")
            self._send_response(200, payload, "application/json; charset=utf-8")
            return

        self._send_response(404, b"Not found", "text/plain; charset=utf-8")

    def do_POST(self) -> None:
        path = urlparse(self.path).path
        if path != "/api/data":
            self._send_response(404, b"Not found", "text/plain; charset=utf-8")
            return

        content_length = int(self.headers.get("Content-Length", "0"))
        raw_body = self.rfile.read(content_length)
        try:
            payload = json.loads(raw_body.decode("utf-8"))
            if not isinstance(payload, dict):
                raise ValueError("Payload must be an object")
            save_state(payload)
        except (json.JSONDecodeError, UnicodeDecodeError, OSError, ValueError) as exc:
            body = json.dumps({"ok": False, "error": str(exc)}, ensure_ascii=False).encode("utf-8")
            self._send_response(400, body, "application/json; charset=utf-8")
            return

        body = json.dumps({"ok": True}, ensure_ascii=False).encode("utf-8")
        self._send_response(200, body, "application/json; charset=utf-8")

    def log_message(self, format: str, *args: Any) -> None:
        return

    def _send_response(self, status_code: int, body: bytes, content_type: str) -> None:
        self.send_response(status_code)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        self.wfile.write(body)


def resolve_port(host: str, preferred_port: int) -> int:
    port = preferred_port
    while True:
        with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
            sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            try:
                sock.bind((host, port))
                return port
            except OSError:
                port += 1


def main() -> None:
    parser = argparse.ArgumentParser(description="Web app cá nhân để theo dõi GPA và điểm trung bình.")
    parser.add_argument("--host", default="127.0.0.1", help="Địa chỉ host để chạy web app.")
    parser.add_argument("--port", type=int, default=8899, help="Cổng chạy web app.")
    parser.add_argument(
        "--no-browser",
        action="store_true",
        help="Khong tu dong mo trinh duyet sau khi khoi dong.",
    )
    args = parser.parse_args()

    actual_port = resolve_port(args.host, args.port)
    server = ThreadingHTTPServer((args.host, actual_port), GradeTrackerHandler)
    url = f"http://127.0.0.1:{actual_port}" if args.host in {"0.0.0.0", "127.0.0.1"} else f"http://{args.host}:{actual_port}"

    print("=" * 78)
    print("WEB APP THEO DOI GPA CA NHAN")
    print("=" * 78)
    print(f"Mo trinh duyet va truy cap: {url}")
    if actual_port != args.port:
        print(f"Cong {args.port} dang ban, app da chuyen sang cong {actual_port}.")
    print(f"Du lieu se duoc luu tai: {DATA_FILE}")
    print("Nhan Ctrl+C trong terminal de dung server.")
    print("=" * 78)

    if not args.no_browser:
        threading.Timer(1.0, lambda: webbrowser.open(url)).start()

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\\nDa dung web app.")
    finally:
        server.server_close()


if __name__ == "__main__":
    main()
