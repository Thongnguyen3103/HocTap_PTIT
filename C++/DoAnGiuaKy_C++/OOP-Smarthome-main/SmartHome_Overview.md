# Tổng quan về Hệ thống Điều khiển Dinh thự Thông minh (Smart Home)

Tài liệu này cung cấp cái nhìn tổng quan về kiến trúc phần mềm, các tính năng hướng đối tượng (OOP) và quy trình hoạt động của hệ thống mô phỏng Dinh thự thông minh (Đề số 5).

---

## 1. Kiến trúc Thiết bị (Device Hierarchy)
Hệ thống được thiết kế theo mô hình hướng đối tượng với lớp cơ sở trừu tượng `Device` làm nền tảng. Tất cả các thiết bị thông minh khác đều kế thừa từ `Device` và ghi đè (override) các phương thức đa hình `toggle()` và `getStatus()`.

Hiện tại hệ thống có **17 lớp thiết bị thông minh** bao gồm:
1. **`Light` (Đèn)**: Điều chỉnh độ sáng từ 0% - 100%.
2. **`Thermostat` (Điều hòa/Bộ điều nhiệt)**: Quản lý nhiệt độ phòng, sưởi ấm, làm mát và bảo vệ quá nhiệt.
3. **`SecurityCamera` (Camera an ninh)**: Yêu cầu xác thực mật khẩu, kiểm soát trạng thái ghi hình.
4. **`SmartLock` (Khóa thông minh)**: Khóa/Mở khóa cửa ra vào.
5. **`Refrigerator` (Tủ lạnh)**: Quản lý nhiệt độ ngăn mát/đông và chế độ làm lạnh nhanh.
6. **`VacuumCleaner` (Robot hút bụi)**: Quản lý pin, các chế độ dọn dẹp (Auto, Spot, Charge).
7. **`WashingMachine` (Máy giặt)**: Chọn chu trình giặt (Cotton, Wool,...) và nhiệt độ nước.
8. **`Dryer` (Máy sấy)**: Cài đặt chế độ sấy và hẹn giờ.
9. **`WaterHeater` (Bình nóng lạnh)**: Điều chỉnh nhiệt độ đun nước ấm.
10. **`SmartTV` (Tivi thông minh)**: Quản lý kênh, âm lượng, nguồn tín hiệu đầu vào (Netflix, YouTube,...).
11. **`Sprinkler` (Hệ thống tưới cây)**: Đặt thời gian và lưu lượng nước tưới sân vườn.
12. **`SmartCurtain` (Rèm cửa)**: Điều chỉnh phần trăm đóng/mở rèm (0% - 100%).
13. **`AirPurifier` (Máy lọc không khí)**: Điều chỉnh tốc độ quạt gió và giám sát chỉ số AQI bụi mịn.
14. **`WaterDispenser` (Máy lọc nước nóng lạnh)**: Quản lý nhiệt độ hai ngăn và chế độ diệt khuẩn UV.
15. **`SoundSystem` (Hệ thống âm thanh)**: Phát/Dừng nhạc, điều chỉnh thể loại nhạc và âm lượng.
16. **`GarageDoor` (Cửa cuốn Garage)**: Đóng/Mở cửa cuốn garage ô tô.
17. **`SmartOven` (Lò nướng)**: Đặt nhiệt độ, thời gian nướng và chế độ nướng.

Hệ thống khởi tạo tổng cộng **24 đối tượng thiết bị cụ thể** đại diện cho các khu vực khác nhau trong căn hộ (phòng khách, phòng ngủ, sân vườn, garage).

---

## 2. Quy trình Hoạt động chính

### Bước 1: Khởi tạo Hub trung tâm và các Thiết bị
- Đối tượng `SmartHomeHub` đóng vai trò là "bộ não" điều phối.
- 24 đối tượng thiết bị được khởi tạo động trên bộ nhớ Heap thông qua con trỏ (`new`).

### Bước 2: Đăng ký thiết bị vào Hub
- Phương thức `myHub.addDevice(Device*)` được gọi để đưa tất cả thiết bị vào danh sách quản lý của Hub, thiết lập liên kết đa hình.

### Bước 3: Đăng ký 25 Kịch bản tự động hóa (Macros)
Hệ thống tích hợp một `MacroSystem` cho phép thiết lập và chạy các chuỗi hành động phối hợp. **25 kịch bản hoạt động** trải dài suốt 24 giờ trong ngày được đăng ký bằng biểu thức Lambda (`function<void()>`):
- **Bình minh (`05:30 - BinhMinh`)**: Mở rèm phòng ngủ, bật nhẹ đèn, bật nước nóng chuẩn bị.
- **Rời nhà (`08:00 - DiLam`)**: Khóa mọi cửa, tắt toàn bộ đèn/điều hòa, bật camera giám sát ghi hình.
- **Trở về nhà (`17:30 - ChaoMungVeNha`)**: Mở khóa cửa chính, mở cửa garage, tắt camera phòng khách để bảo vệ sự riêng tư, bật đèn ấm áp.
- **Xem phim (`20:00 - GiaiTri`)**: Chuyển tivi sang Netflix, giảm đèn phòng khách còn 15% tạo không gian rạp phim.
- **Chúc ngủ ngon (`22:45 - ChucNguNgon`)**: Khóa chặt cửa chính/garage, tắt đèn tầng dưới, đặt điều hòa phòng ngủ 26 độ C, bật camera sân vườn canh trộm đêm.
- *Cùng nhiều kịch bản khác phục vụ tưới cây, dọn nhà, giặt sấy đồ, tập thể dục, tuần tra đêm, tiết kiệm điện rạng sáng.*

### Bước 4: Điều khiển tương tác qua Menu tiếng Việt
Khi chạy chương trình, người dùng được cung cấp một **Menu console dạng số hiển thị bằng chữ tiếng Việt**:
- **Từ 1 - 25**: Kích hoạt nhanh 25 kịch bản hoạt động trong ngày.
- **[26]**: Xem trạng thái (status) chi tiết của toàn bộ 24 thiết bị cùng lúc.
- **[27]**: Bật/Tắt thiết bị đơn lẻ theo ID chỉ định bằng phương thức đa hình `toggle()`.
- **[28]**: Mô phỏng sự cố và kích hoạt khắc phục sự cố phần cứng.
- **[29]**: Thoát hệ thống.

---

## 3. Quản lý Sự cố và Xử lý Ngoại lệ (Exceptions & Operator Overloading)

### Lỗi Truy cập Trái phép (UnauthorizedAccessException)
- Nếu người dùng cố gắng thao tác `toggle()` trên `SecurityCamera` khi chưa xác thực mật khẩu đúng (`"admin321"`), hệ thống sẽ ném ra ngoại lệ `UnauthorizedAccessException` được bắt ở khối `try-catch` để cảnh báo bảo mật.

### Lỗi Vòng lặp Phản hồi (FeedbackLoopException)
- Khi gọi `forceFeedbackLoop()` trên lớp `Thermostat`, thiết bị sẽ giả lập tình huống nhiệt độ môi trường biến động cực đoan liên tục (nóng lạnh đột ngột làm bộ sưởi và làm mát kích hoạt xen kẽ liên tục). Khi số chu kỳ đạt giới hạn tối đa `MAX_FEEDBACK`, hệ thống ném ra `FeedbackLoopException` để dừng khẩn cấp thiết bị bảo vệ phần cứng.

### Mô phỏng Trục trặc thiết bị (Toán tử !)
- Toán tử `!` được nạp chồng (operator overloading) cho lớp cơ sở `Device` để giả lập lỗi:
  - Lần tác động thứ nhất: Chuyển thiết bị sang trạng thái lỗi (`isError = true`), tắt thiết bị và báo sự cố.
  - Lần tác động thứ hai: Reset thiết bị, trả về trạng thái bình thường (`isError = false`) và khôi phục thành công.
- `SmartHomeHub::triggerDeviceFault(Device*)` sử dụng toán tử này để thực hiện quét thiết bị: Phát hiện lỗi -> tự động gửi lệnh reset khôi phục giúp hệ thống hoạt động ổn định.
