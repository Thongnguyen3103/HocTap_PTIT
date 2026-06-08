# Hướng Dẫn Sử Dụng Môi Trường Anaconda Của Bạn 🚀

Chào mừng bạn! Hệ thống đã kiểm tra và phát hiện **Anaconda đã được cài đặt thành công** trên máy tính của bạn tại đường dẫn:
`C:\Users\minht\anaconda3`

Dưới đây là hướng dẫn chi tiết và tối ưu nhất để bạn có thể sử dụng môi trường này để lập trình Python ngay lập tức.

---

## 1. Cách chạy Python với Anaconda ngay bây giờ

Để kiểm tra nhanh, bạn có thể mở terminal trong VS Code và chạy file `test_conda.py` bằng lệnh sau:
```powershell
& "C:\Users\minht\anaconda3\python.exe" d:\Coder_Hoctap\Python\test_conda.py
```

---

## 2. Cách chọn môi trường Anaconda trong VS Code (Khuyên dùng) 🛠️

Để VS Code tự động nhận dạng môi trường Anaconda của bạn (không cần gõ đường dẫn dài dòng):

1. Mở bất kỳ file `.py` nào (ví dụ: [test_conda.py](file:///d:/Coder_Hoctap/Python/test_conda.py)).
2. Nhấn tổ hợp phím **`Ctrl + Shift + P`** để mở Command Palette.
3. Gõ **`Python: Select Interpreter`** và nhấn `Enter`.
4. VS Code sẽ hiển thị danh sách các môi trường Python. Hãy chọn môi trường có chữ **`conda`** hoặc chọn đường dẫn:
   `C:\Users\minht\anaconda3\python.exe`
5. Sau khi chọn, bạn chỉ cần nhấn nút **Run (Tam giác góc phải màn hình)** hoặc phím **`F5`** để chạy code một cách cực kỳ mượt mà!

---

## 3. Cách sử dụng lệnh `conda` trong Terminal 💻

Hiện tại lệnh `conda` chưa được nhận diện trực tiếp trong PowerShell thông thường do chính sách bảo mật Windows và đường dẫn chưa được thêm vào biến môi trường (PATH). Có 2 giải pháp tối ưu dành cho bạn:

### Giải pháp A: Sử dụng Anaconda PowerShell Prompt (Dễ nhất & Chuẩn nhất)
1. Nhấn nút **Windows (Start Menu)** trên bàn phím.
2. Gõ tìm kiếm **"Anaconda PowerShell Prompt"** hoặc **"Anaconda Prompt"** và mở nó lên.
3. Terminal này đã được cấu hình sẵn hoàn toàn, bạn có thể gõ trực tiếp:
   - `conda --version`
   - `python --version`
   - `conda install <tên_thư_viện>`

### Giải pháp B: Kích hoạt conda cho PowerShell mặc định
Nếu bạn muốn sử dụng lệnh `conda` trực tiếp trong PowerShell của VS Code, hãy làm theo các bước sau:
1. Mở PowerShell với quyền Administrator (nhấp chuột phải vào PowerShell -> Run as Administrator).
2. Chạy lệnh sau để cho phép chạy script cấu hình của Conda:
   ```powershell
   Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
   ```
3. Sau đó khởi động lại VS Code, conda sẽ tự động hoạt động!

---

## 4. Các lệnh Conda thông dụng bạn nên biết 📚

| Lệnh | Công dụng |
| :--- | :--- |
| `conda env list` | Xem danh sách các môi trường ảo hiện có |
| `conda create -n ten_moi_truong python=3.11` | Tạo một môi trường ảo mới với phiên bản Python chỉ định |
| `conda activate ten_moi_truong` | Kích hoạt môi trường ảo để sử dụng |
| `conda deactivate` | Thoát khỏi môi trường ảo hiện tại |
| `conda install ten_package` | Cài đặt thư viện mới vào môi trường ảo |

---

> [!TIP]
> File test môi trường [test_conda.py](file:///d:/Coder_Hoctap/Python/test_conda.py) đã được tạo sẵn trong thư mục học tập của bạn. Bạn hãy làm theo **Mục 2** để chọn Interpreter và chạy thử xem kết quả hiển thị tuyệt đẹp thế nào nhé!
