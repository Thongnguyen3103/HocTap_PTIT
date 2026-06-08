#include <iostream>
#include <string>
#include <vector>
#include <functional>

// Khai báo các Header của các thiết bị có sẵn ban đầu
#include "SmartHomeHub.h"
#include "MacroSystem.h"
#include "Light.h"
#include "Thermostat.h"
#include "SecurityCamera.h"
#include "SmartLock.h"

// Khai báo các Header của các thiết bị mới đợt 1
#include "Refrigerator.h"
#include "VacuumCleaner.h"
#include "WashingMachine.h"
#include "Dryer.h"
#include "WaterHeater.h"
#include "SmartTV.h"
#include "Sprinkler.h"

// Khai báo các Header của các thiết bị mới đợt 2 (hoàn thiện ngôi nhà thông minh)
#include "SmartCurtain.h"
#include "AirPurifier.h"
#include "WaterDispenser.h"
#include "SoundSystem.h"
#include "GarageDoor.h"
#include "SmartOven.h"

using namespace std;

int main() {
    system("chcp 65001 > nul"); // Thiết lập console Windows hỗ trợ UTF-8 hiển thị tiếng Việt có dấu
    // 1. KHỞI TẠO BỘ ĐIỀU KHIỂN TRUNG TÂM (Đóng vai trò là bộ não của ngôi nhà)
    SmartHomeHub myHub("HỆ THỐNG TRUNG TÂM DINH THỰ THÔNG MINH");

    // 2. KHỞI TẠO 24 THIẾT BỊ THÔNG MINH CHO CẢ NGÔI NHÀ
    // Đèn chiếu sáng
    Light *den_phong_khach = new Light(1, "Den Phong Khach", 90);
    Light *den_phong_ngu = new Light(3, "Den Phong Ngu", 70);
    Light *den_hien_nha = new Light(10, "Den Hien Nha", 0);
    Light *den_ban_cong = new Light(11, "Den Ban Cong", 0);

    // Điều hòa / Bộ điều nhiệt
    Thermostat *dieu_hoa_phong_khach = new Thermostat(2, "Dieu Hoa Phong Khach", 30.0f, 28.5f);
    Thermostat *dieu_hoa_phong_ngu = new Thermostat(4, "Dieu Hoa Phong Ngu", 25.0f, 22.0f);

    // Hệ thống camera an ninh
    SecurityCamera *cam_phong_khach = new SecurityCamera(5, "Cam Phong Khach", "Phong Khach");
    SecurityCamera *cam_phong_ngu = new SecurityCamera(6, "Cam Phong Ngu", "Phong Ngu");
    SecurityCamera *cam_san_vuon = new SecurityCamera(12, "Cam San Vuon", "San Vuon");

    // Khóa cửa & Cửa Garage
    SmartLock *khoa_cua_chinh = new SmartLock(7, "Cua Chinh", false);
    GarageDoor *cua_garage = new GarageDoor(25, "Cua Cuon Garage");

    // Thiết bị gia dụng nhà bếp
    Refrigerator *tu_lanh = new Refrigerator(13, "Tu Lanh Panasonic", 4.0f, -18.0f);
    WaterDispenser *may_loc_nuoc = new WaterDispenser(23, "May Loc Nuoc Karofi");
    SmartOven *lo_nuong = new SmartOven(26, "Lo Nuong Bosch");

    // Thiết bị vệ sinh & Làm sạch
    VacuumCleaner *robot_hut_bui = new VacuumCleaner(14, "Robot Hut Bui Roborock");
    WashingMachine *may_giat = new WashingMachine(15, "May Giat Electrolux");
    Dryer *may_say = new Dryer(16, "May Say LG");
    AirPurifier *may_loc_khong_khi = new AirPurifier(22, "May Loc Khong Khi Xiaomi");

    // Thiết bị tiện ích & Giải trí
    WaterHeater *binh_nuoc_nong = new WaterHeater(17, "Binh Nuoc Nong Ariston");
    SmartTV *tivi_phong_khach = new SmartTV(18, "Tivi Sony Bravia");
    SoundSystem *loa_am_thanh = new SoundSystem(24, "Loa Bose Phong Khach");
    Sprinkler *he_thong_tuoi_cay = new Sprinkler(19, "Voi Tuoi San Vuon");

    // Hệ thống rèm cửa tự động
    SmartCurtain *rem_cua_phong_ngu = new SmartCurtain(20, "Rem Cua Phong Ngu");
    SmartCurtain *rem_cua_phong_khach = new SmartCurtain(21, "Rem Cua Phong Khach");

    // 3. KẾT NỐI VÀ ĐĂNG KÝ TẤT CẢ 24 THIẾT BỊ VÀO HUB TRUNG TÂM
    myHub.addDevice(den_phong_khach);
    myHub.addDevice(dieu_hoa_phong_khach);
    myHub.addDevice(den_phong_ngu);
    myHub.addDevice(dieu_hoa_phong_ngu);
    myHub.addDevice(cam_phong_khach);
    myHub.addDevice(cam_phong_ngu);
    myHub.addDevice(khoa_cua_chinh);
    myHub.addDevice(den_hien_nha);
    myHub.addDevice(den_ban_cong);
    myHub.addDevice(cam_san_vuon);
    myHub.addDevice(tu_lanh);
    myHub.addDevice(robot_hut_bui);
    myHub.addDevice(may_giat);
    myHub.addDevice(may_say);
    myHub.addDevice(binh_nuoc_nong);
    myHub.addDevice(tivi_phong_khach);
    myHub.addDevice(he_thong_tuoi_cay);
    myHub.addDevice(rem_cua_phong_ngu);
    myHub.addDevice(rem_cua_phong_khach);
    myHub.addDevice(may_loc_khong_khi);
    myHub.addDevice(may_loc_nuoc);
    myHub.addDevice(loa_am_thanh);
    myHub.addDevice(cua_garage);
    myHub.addDevice(lo_nuong);

    // 4. THIẾT LẬP VÀ ĐĂNG KÝ 25 KỊCH BẢN HOẠT ĐỘNG TRONG NGÀY (MACROS)
    MacroSystem& ms = myHub.getMacroSystem();

    // Kịch bản 1: 05:30 - Bình minh thức giấc
    ms.addMacro("05:30 - BinhMinh", vector<function<void()>>{
        [=]() { den_phong_ngu->setBrightness(30); },                  // Bật đèn phòng ngủ sáng nhẹ 30%
        [=]() { rem_cua_phong_ngu->setOpenPercent(100); },             // Mở rèm phòng ngủ đón ánh bình minh
        [=]() { if(dieu_hoa_phong_ngu->getIsOn()) dieu_hoa_phong_ngu->toggle(); }, // Tắt điều hòa phòng ngủ
        [=]() { binh_nuoc_nong->setTargetTemp(45.0f); },             // Bình nước nóng đặt 45 độ C
        [=]() { binh_nuoc_nong->startHeating(); }                     // Bắt đầu đun nước nóng tắm sáng
    });

    // Kịch bản 2: 07:00 - Chuẩn bị ăn sáng
    ms.addMacro("07:00 - BuoiSang", vector<function<void()>>{
        [=]() { den_phong_khach->setBrightness(60); },                // Bật đèn phòng khách 60%
        [=]() { rem_cua_phong_khach->setOpenPercent(100); },           // Mở rèm phòng khách rộng đón nắng
        [=]() { dieu_hoa_phong_khach->setTargetTemp(26.0f); },        // Đặt điều hòa phòng khách 26.0 độ C
        [=]() { if(!dieu_hoa_phong_khach->getIsOn()) dieu_hoa_phong_khach->toggle(); }, // Bật điều hòa phòng khách
        [=]() { tivi_phong_khach->toggle(); },                        // Bật tivi Sony
        [=]() { tivi_phong_khach->setChannel(1); }                    // Mở VTV1
    });

    // Kịch bản 3: 07:30 - Tưới cây buổi sáng
    ms.addMacro("07:30 - TuoiCaySang", vector<function<void()>>{
        [=]() { he_thong_tuoi_cay->startWatering(15, 12); }           // Tưới cây 15 phút với lưu lượng 12 L/phút
    });

    // Kịch bản 4: 08:00 - Rời nhà đi làm (Chế độ khóa an toàn & kích hoạt camera)
    ms.addMacro("08:00 - DiLam", vector<function<void()>>{
        [=]() { den_phong_khach->setBrightness(0); },                 // Tắt đèn phòng khách
        [=]() { den_phong_ngu->setBrightness(0); },                   // Tắt đèn phòng ngủ
        [=]() { den_hien_nha->setBrightness(0); },                    // Tắt đèn hiên nhà
        [=]() { den_ban_cong->setBrightness(0); },                    // Tắt đèn ban công
        [=]() { rem_cua_phong_khach->setOpenPercent(0); },            // Khép rèm phòng khách tránh nắng gắt ban ngày
        [=]() { rem_cua_phong_ngu->setOpenPercent(0); },              // Khép rèm phòng ngủ
        [=]() { if(dieu_hoa_phong_khach->getIsOn()) dieu_hoa_phong_khach->toggle(); }, // Tắt điều hòa phòng khách
        [=]() { if(tivi_phong_khach->getIsOn()) tivi_phong_khach->toggle(); },         // Tắt tivi phòng khách
        [=]() { if(loa_am_thanh->getIsOn()) loa_am_thanh->toggle(); },                 // Tắt loa phát nhạc
        [=]() { khoa_cua_chinh->locked(); },                          // Khóa chặt cửa chính ra vào
        [=]() { cua_garage->closeDoor(); },                           // Đóng cửa cuốn garage xe
        [=]() { cam_phong_khach->authenticate("admin321"); },         // Xác thực camera phòng khách
        [=]() { cam_phong_khach->startRecording(); },                 // Bật ghi hình giám sát
        [=]() { cam_phong_ngu->authenticate("admin321"); },           // Xác thực camera phòng ngủ
        [=]() { cam_phong_ngu->startRecording(); },                   // Bật ghi hình
        [=]() { cam_san_vuon->authenticate("admin321"); },            // Xác thực camera sân vườn
        [=]() { cam_san_vuon->startRecording(); }                     // Bật ghi hình
    });

    // Kịch bản 5: 08:30 - Dọn dẹp tự động khi nhà vắng người
    ms.addMacro("08:30 - DonDepTuDong", vector<function<void()>>{
        [=]() { robot_hut_bui->startCleaning(); }                     // Robot Roborock rời dock đi dọn toàn nhà
    });

    // Kịch bản 6: 09:30 - Máy giặt hoạt động
    ms.addMacro("09:30 - GiatDo", vector<function<void()>>{
        [=]() { may_giat->setCycle("Cotton"); },                      // Đồ Cotton thường ngày
        [=]() { may_giat->setWaterTemp(40); },                        // Nước nóng 40C diệt khuẩn
        [=]() { may_giat->startWash(); }                              // Kích hoạt giặt
    });

    // Kịch bản 7: 10:30 - Sấy quần áo
    ms.addMacro("10:30 - SayDo", vector<function<void()>>{
        [=]() { may_say->setDryMode("Eco"); },                        // Sấy chế độ sinh thái tiết kiệm điện
        [=]() { may_say->setDryTime(60); },                          // Sấy trong 60 phút
        [=]() { may_say->startDry(); }                                // Bắt đầu sấy đồ
    });

    // Kịch bản 8: 11:30 - Robot hoàn tất dọn dẹp và về sạc
    ms.addMacro("11:30 - RobotSac", vector<function<void()>>{
        [=]() { robot_hut_bui->dockAndCharge(); }                     // Robot tự động quay về sạc điện
    });

    // Kịch bản 9: 12:00 - Nghỉ trưa mát mẻ phòng khách
    ms.addMacro("12:00 - TruaMatMe", vector<function<void()>>{
        [=]() { dieu_hoa_phong_khach->setTargetTemp(24.0f); },        // Giảm điều hòa mát sâu 24 độ C
        [=]() { den_phong_khach->setBrightness(40); },                // Giảm bớt đèn phòng khách
        [=]() { rem_cua_phong_khach->setOpenPercent(30); },           // Mở nhẹ rèm lấy chút ánh sáng tự nhiên
        [=]() { if(!tivi_phong_khach->getIsOn()) tivi_phong_khach->toggle(); }, // Bật tivi phòng khách
        [=]() { tivi_phong_khach->setInputSource("Netflix"); }         // Mở ứng dụng xem phim giải trí
    });

    // Kịch bản 10: 13:30 - Đi ngủ trưa (Phòng ngủ thoải mái)
    ms.addMacro("13:30 - NghiTrua", vector<function<void()>>{
        [=]() { if(tivi_phong_khach->getIsOn()) tivi_phong_khach->toggle(); },  // Tắt tivi phòng khách
        [=]() { den_phong_khach->setBrightness(0); },                 // Tắt đèn phòng khách
        [=]() { dieu_hoa_phong_ngu->setTargetTemp(25.0f); },          // Đặt điều hòa phòng ngủ 25 độ C
        [=]() { if(!dieu_hoa_phong_ngu->getIsOn()) dieu_hoa_phong_ngu->toggle(); }, // Bật điều hòa phòng ngủ
        [=]() { den_phong_ngu->setBrightness(10); },                  // Đèn ngủ 10%
        [=]() { rem_cua_phong_ngu->setOpenPercent(0); }               // Đóng kín rèm tối phòng để dễ ngủ
    });

    // Kịch bản 11: 14:30 - Bắt đầu làm việc chiều
    ms.addMacro("14:30 - LamViec", vector<function<void()>>{
        [=]() { den_phong_ngu->setBrightness(0); },                   // Tắt đèn phòng ngủ
        [=]() { if(dieu_hoa_phong_ngu->getIsOn()) dieu_hoa_phong_ngu->toggle(); }, // Tắt điều hòa phòng ngủ
        [=]() { den_phong_khach->setBrightness(85); },                // Bật đèn phòng khách 85% sáng rõ làm việc
        [=]() { dieu_hoa_phong_khach->setTargetTemp(24.5f); },        // Điều hòa mát dễ chịu 24.5 độ C
        [=]() { may_loc_khong_khi->toggle(); },                       // Bật máy lọc không khí bảo vệ hô hấp
        [=]() { may_loc_khong_khi->setFanSpeed(2); }                  // Để tốc độ quạt lọc mức trung bình
    });

    // Kịch bản 12: 15:30 - Tủ lạnh cấp đông nhanh chuẩn bị làm đá mát cho bữa xế
    ms.addMacro("15:30 - SuperCoolTuLanh", vector<function<void()>>{
        [=]() { tu_lanh->setSuperCool(true); }                        // Ướp lạnh nhanh đồ uống
    });

    // Kịch bản 13: 16:30 - Tưới cây buổi chiều mát
    ms.addMacro("16:30 - TuoiCayChieu", vector<function<void()>>{
        [=]() { he_thong_tuoi_cay->startWatering(10, 8); }            // Tưới nhẹ vườn rau ban công trong 10 phút
    });

    // Kịch bản 14: 17:00 - Đun nước nóng sẵn sàng cho cả nhà tắm chiều
    ms.addMacro("17:00 - DunNuocNong", vector<function<void()>>{
        [=]() { binh_nuoc_nong->setTargetTemp(50.0f); },              // Đặt nhiệt độ nóng cao hơn để tắm thoải mái
        [=]() { binh_nuoc_nong->startHeating(); }                     // Bắt đầu đun nước
    });

    // Kịch bản 15: 17:30 - Chào mừng về nhà (Welcome Home!)
    ms.addMacro("17:30 - ChaoMungVeNha", vector<function<void()>>{
        [=]() { khoa_cua_chinh->unlocked(); },                        // Mở khóa cửa chính đón chủ nhân
        [=]() { cua_garage->openDoor(); },                            // Mở cửa cuốn garage cất xe oto
        [=]() { cam_phong_khach->authenticate("admin321"); },         // Xác thực camera phòng khách
        [=]() { cam_phong_khach->toggle(); },                         // Tắt ghi hình camera phòng khách để bảo mật riêng tư
        [=]() { den_hien_nha->setBrightness(100); },                  // Bật đèn hiên rực rỡ đón lối đi vào
        [=]() { den_phong_khach->setBrightness(75); },                // Bật đèn phòng khách 75% ấm cúng
        [=]() { if(!may_loc_khong_khi->getIsOn()) may_loc_khong_khi->toggle(); }, // Bật lọc khí tươi sạch
        [=]() { may_loc_khong_khi->setFanSpeed(3); }                  // Bật tối đa quạt lọc không khí sạch ngay
    });

    // Kịch bản 16: 18:30 - Chuẩn bị nấu ăn tối
    ms.addMacro("18:30 - NauAn", vector<function<void()>>{
        [=]() { den_phong_khach->setBrightness(90); },                // Đèn bật sáng tối đa khu vực sinh hoạt
        [=]() { dieu_hoa_phong_khach->setTargetTemp(24.0f); },        // Đặt điều hòa 24 độ
        [=]() { lo_nuong->toggle(); },                                // Bật lò nướng làm nóng lò sẵn sàng
        [=]() { if(!tivi_phong_khach->getIsOn()) tivi_phong_khach->toggle(); }, // Bật tivi
        [=]() { tivi_phong_khach->setInputSource("YouTube"); },       // Bật nhạc YouTube
        [=]() { tivi_phong_khach->setVolume(20); }                    // Âm lượng vừa phải
    });

    // Kịch bản 17: 19:30 - Bữa tối gia đình ấm cúng
    ms.addMacro("19:30 - BuaToi", vector<function<void()>>{
        [=]() { lo_nuong->toggle(); },                                // Tắt lò nướng sau khi nấu xong
        [=]() { den_phong_khach->setBrightness(55); },                // Giảm nhẹ đèn vàng ấm cúng ăn cơm
        [=]() { if(!loa_am_thanh->getIsOn()) loa_am_thanh->toggle(); }, // Bật hệ thống âm thanh
        [=]() { loa_am_thanh->setGenre("Jazz"); },                     // Mở nhạc Jazz êm dịu bữa ăn
        [=]() { loa_am_thanh->setVolume(15); },                       // Âm lượng nhẹ nhàng 15%
        [=]() { loa_am_thanh->playMusic(); },
        [=]() { if(tivi_phong_khach->getIsOn()) tivi_phong_khach->toggle(); } // Tắt tivi tập trung ăn cơm
    });

    // Kịch bản 18: 20:00 - Giải trí xem phim buổi tối
    ms.addMacro("20:00 - GiaiTri", vector<function<void()>>{
        [=]() { if(loa_am_thanh->getIsOn()) loa_am_thanh->toggle(); },  // Tắt nhạc Jazz phòng ăn
        [=]() { if(!tivi_phong_khach->getIsOn()) tivi_phong_khach->toggle(); }, // Bật tivi chính phòng khách
        [=]() { tivi_phong_khach->setInputSource("Netflix"); },       // Mở ứng dụng xem phim Netflix
        [=]() { tivi_phong_khach->setVolume(28); },                   // Âm lượng 28% cuốn hút
        [=]() { den_phong_khach->setBrightness(15); },                // Đèn phòng khách hạ còn 15% giống rạp phim
        [=]() { rem_cua_phong_khach->setOpenPercent(0); },            // Khép rèm để tránh lọt ánh sáng bên ngoài vào
        [=]() { khoa_cua_chinh->locked(); }                           // Khóa cửa chính tự động phòng gian
    });

    // Kịch bản 19: 20:45 - Tập thể dục rèn luyện sức khỏe trong nhà
    ms.addMacro("20:45 - TheDuc", vector<function<void()>>{
        [=]() { dieu_hoa_phong_khach->setTargetTemp(20.0f); },        // Hạ điều hòa 20 độ mát sâu khi tập ra mồ hôi
        [=]() { tivi_phong_khach->setInputSource("YouTube"); },       // Mở nhạc thể thao Remix sôi động trên YouTube
        [=]() { tivi_phong_khach->setVolume(35); },                   // Tăng âm lượng to 35% kích thích tinh thần
        [=]() { den_phong_khach->setBrightness(90); }                 // Tăng độ sáng phòng tập 90%
    });

    // Kịch bản 20: 21:45 - Kích hoạt robot dọn dẹp nhanh phòng khách sau hoạt động
    ms.addMacro("21:45 - VeSinhThietBi", vector<function<void()>>{
        [=]() { robot_hut_bui->setWorkMode("Spot"); },                // Chế độ dọn cục bộ tại sàn phòng khách
        [=]() { robot_hut_bui->startCleaning(); }                     // Bắt đầu dọn nhanh
    });

    // Kịch bản 21: 22:15 - Thư giãn trước khi ngủ
    ms.addMacro("22:15 - ThuGianNhe", vector<function<void()>>{
        [=]() { if(tivi_phong_khach->getIsOn()) tivi_phong_khach->toggle(); },  // Tắt tivi phòng khách
        [=]() { if(robot_hut_bui->getIsOn()) robot_hut_bui->dockAndCharge(); }, // Đưa robot về sạc không làm ồn
        [=]() { binh_nuoc_nong->setTargetTemp(40.0f); },              // Đặt nước nóng ấm nhẹ thư giãn cơ thể
        [=]() { binh_nuoc_nong->startHeating(); },                    // Bật đun nước ấm
        [=]() { den_phong_ngu->setBrightness(45); },                  // Bật đèn phòng ngủ 45% ấm cúng chuẩn bị nghỉ
        [=]() { rem_cua_phong_ngu->setOpenPercent(0); }               // Đóng rèm kín hoàn toàn
    });

    // Kịch bản 22: 22:45 - Đi ngủ (Chúc ngủ ngon)
    ms.addMacro("22:45 - ChucNguNgon", vector<function<void()>>{
        [=]() { khoa_cua_chinh->locked(); },                          // Khóa chặt cửa chính
        [=]() { cua_garage->closeDoor(); },                           // Đóng cửa cuốn garage xe
        [=]() { den_phong_khach->setBrightness(0); },                 // Tắt toàn bộ đèn phòng khách
        [=]() { den_hien_nha->setBrightness(20); },                    // Đèn hiên ngoài nhà duy trì 20% an ninh
        [=]() { den_ban_cong->setBrightness(10); },                   // Đèn ban công 10% mờ
        [=]() { den_phong_ngu->setBrightness(5); },                   // Đèn ngủ 5% cực dịu
        [=]() { dieu_hoa_phong_ngu->setTargetTemp(26.0f); },          // Điều hòa phòng ngủ 26 độ dễ chịu suốt đêm
        [=]() { if(!dieu_hoa_phong_ngu->getIsOn()) dieu_hoa_phong_ngu->toggle(); }, // Bật điều hòa phòng ngủ
        [=]() { cam_san_vuon->authenticate("admin321"); },            // Xác thực camera ngoài vườn
        [=]() { cam_san_vuon->startRecording(); },                    // Bật ghi hình ban đêm sân vườn
        [=]() { if(may_loc_khong_khi->getIsOn()) may_loc_khong_khi->setFanSpeed(1); } // Để máy lọc khí chạy êm ru mức 1
    });

    // Kịch bản 23: 00:00 - Tuần tra giữa đêm
    ms.addMacro("00:00 - TuanTraDem", vector<function<void()>>{
        [=]() { cam_phong_khach->authenticate("admin321"); },         // Xác thực camera phòng khách
        [=]() { cam_phong_khach->startRecording(); },                 // Kích hoạt ghi hình ban đêm đề phòng đột nhập trong nhà
        [=]() { khoa_cua_chinh->locked(); }                           // Đảm bảo cửa chính luôn khóa chặt chẽ
    });

    // Kịch bản 24: 02:00 - Nửa đêm tiết kiệm điện năng
    ms.addMacro("02:00 - TietKiemDem", vector<function<void()>>{
        [=]() { dieu_hoa_phong_ngu->setTargetTemp(27.0f); }           // Tăng nhiệt độ ngủ lên 27 độ giúp cơ thể không bị lạnh và tiết kiệm điện
    });

    // Kịch bản 25: 04:00 - Cảnh giác lúc rạng sáng
    ms.addMacro("04:00 - CanhGiacSANG", vector<function<void()>>{
        [=]() { cam_san_vuon->authenticate("admin321"); },            // Xác thực camera sân vườn cổng ngoài
        [=]() { cam_san_vuon->startRecording(); }                     // Ghi hình chặt chẽ đề phòng kẻ gian lúc trời chuyển sáng sáng
    });

    // 5. GIAO DIỆN TƯƠNG TÁC THÂN THIỆN BẰNG MENU SỐ TIẾNG VIỆT RÕ NGHĨA
    while (true) {
        cout << "\n=====================================================================" << endl;
        cout << "                 Bảng điều khiển hệ thống SmartHome                  " << endl;
        cout << "=====================================================================" << endl;
        cout << "  [1]  Bình minh thức giấc (05:30)         [14] Đun nước nóng tắm chiều (17:00)" << endl;
        cout << "  [2]  Chuẩn bị ăn sáng (07:00)            [15] Chào mừng về nhà (17:30)" << endl;
        cout << "  [3]  Tưới cây buổi sáng (07:30)          [16] Chuẩn bị nấu ăn tối (18:30)" << endl;
        cout << "  [4]  Rời nhà đi làm (08:00)              [17] Bữa tối ấm cúng (19:30)" << endl;
        cout << "  [5]  Dọn dẹp tự động (08:30)             [18] Giải trí xem phim (20:00)" << endl;
        cout << "  [6]  Máy giặt hoạt động (09:30)          [19] Tập thể dục trong nhà (20:45)" << endl;
        cout << "  [7]  Sấy quần áo tự động (10:30)         [20] Robot vệ sinh nhanh (21:45)" << endl;
        cout << "  [8]  Robot về để sạc pin (11:30)         [21] Thư giãn trước khi ngủ (22:15)" << endl;
        cout << "  [9]  Nghỉ trưa mát mẻ (12:00)            [22] Đi ngủ (Chúc ngủ ngon) (22:45)" << endl;
        cout << "  [10] Đi ngủ trưa phòng ngủ (13:30)       [23] Tuần tra giữa đêm (00:00)" << endl;
        cout << "  [11] Bắt đầu làm việc chiều (14:30)      [24] Nửa đêm tiết kiệm điện (02:00)" << endl;
        cout << "  [12] Tủ lạnh cấp đông nhanh (15:30)      [25] Cảnh giác rạng sáng (04:00)" << endl;
        cout << "  [13] Tưới cây buổi chiều (16:30)" << endl;
        cout << "---------------------------------------------------------------------" << endl;
        cout << "  [26] Xem trạng thái của tất cả 24 thiết bị trong dinh thự" << endl;
        cout << "  [27] Bật/Tắt thiết bị đơn lẻ bằng cách chọn ID" << endl;
        cout << "  [28] Mô phỏng sự cố phần cứng và tự động sửa lỗi (Toán tử !)" << endl;
        cout << "  [29] Thoát chương trình" << endl;
        cout << "=====================================================================" << endl;
        cout << "Chọn tùy chọn của bạn (1-29): ";

        string input;
        if (!getline(cin, input)) {
            break;
        }
        // Khử BOM UTF-8 (EF BB BF) nếu có ở đầu file khi chuyển hướng đầu vào
        if (input.size() >= 3 && (unsigned char)input[0] == 0xEF && (unsigned char)input[1] == 0xBB && (unsigned char)input[2] == 0xBF) {
            input = input.substr(3);
        }
        if (!input.empty() && input.back() == '\r') {
            input.pop_back();
        }

        int choice = 0;
        try {
            choice = stoi(input);
        } catch (...) {
            cout << "[LỖI] Vui lòng nhập một con số hợp lệ từ 1 đến 29!" << endl;
            continue;
        }

        if (choice >= 1 && choice <= 25) {
            string selectedMacro = "";
            switch (choice) {
                case 1:  selectedMacro = "05:30 - BinhMinh"; break;
                case 2:  selectedMacro = "07:00 - BuoiSang"; break;
                case 3:  selectedMacro = "07:30 - TuoiCaySang"; break;
                case 4:  selectedMacro = "08:00 - DiLam"; break;
                case 5:  selectedMacro = "08:30 - DonDepTuDong"; break;
                case 6:  selectedMacro = "09:30 - GiatDo"; break;
                case 7:  selectedMacro = "10:30 - SayDo"; break;
                case 8:  selectedMacro = "11:30 - RobotSac"; break;
                case 9:  selectedMacro = "12:00 - TruaMatMe"; break;
                case 10: selectedMacro = "13:30 - NghiTrua"; break;
                case 11: selectedMacro = "14:30 - LamViec"; break;
                case 12: selectedMacro = "15:30 - SuperCoolTuLanh"; break;
                case 13: selectedMacro = "16:30 - TuoiCayChieu"; break;
                case 14: selectedMacro = "17:00 - DunNuocNong"; break;
                case 15: selectedMacro = "17:30 - ChaoMungVeNha"; break;
                case 16: selectedMacro = "18:30 - NauAn"; break;
                case 17: selectedMacro = "19:30 - BuaToi"; break;
                case 18: selectedMacro = "20:00 - GiaiTri"; break;
                case 19: selectedMacro = "20:45 - TheDuc"; break;
                case 20: selectedMacro = "21:45 - VeSinhThietBi"; break;
                case 21: selectedMacro = "22:15 - ThuGianNhe"; break;
                case 22: selectedMacro = "22:45 - ChucNguNgon"; break;
                case 23: selectedMacro = "00:00 - TuanTraDem"; break;
                case 24: selectedMacro = "02:00 - TietKiemDem"; break;
                case 25: selectedMacro = "04:00 - CanhGiacSANG"; break;
            }
            cout << "\n==============================================" << endl;
            cout << "  KÍCH HOẠT KỊCH BẢN: " << selectedMacro << endl;
            cout << "==============================================" << endl;
            ms.execute(selectedMacro);
            cout << "==============================================" << endl;
        }
        else if (choice == 26) {
            myHub.allStatus();
        }
        else if (choice == 27) {
            myHub.listDevices();
            cout << "Nhập ID thiết bị bạn muốn điều khiển bật/tắt: ";
            string devStr;
            if (getline(cin, devStr)) {
                if (!devStr.empty() && devStr.back() == '\r') {
                    devStr.pop_back();
                }
                try {
                    int devId = stoi(devStr);
                    myHub.toggleDevice(devId);
                } catch (...) {
                    cout << "[LỖI] ID thiết bị không hợp lệ!" << endl;
                }
            }
        }
        else if (choice == 28) {
            myHub.listDevices();
            cout << "Nhập ID thiết bị bạn muốn mô phỏng lỗi để sửa (Toán tử !): ";
            string faultStr;
            if (getline(cin, faultStr)) {
                if (!faultStr.empty() && faultStr.back() == '\r') {
                    faultStr.pop_back();
                }
                try {
                    int devId = stoi(faultStr);
                    myHub.malfunctionDevice(devId);
                } catch (...) {
                    cout << "[LỖI] ID thiết bị không hợp lệ!" << endl;
                }
            }
        }
        else if (choice == 29) {
            cout << "\nĐang đóng hệ thống điều khiển Dinh thự. Tạm biệt!" << endl;
            break;
        }
        else {
            cout << "[LỖI] Tùy chọn không hợp lệ! Vui lòng nhập từ 1 đến 29." << endl;
        }
    }

    // GIẢI PHÓNG BỘ NHỚ ĐỘNG (Tránh tràn bộ nhớ - Leak Memory)
    delete den_phong_khach;
    delete dieu_hoa_phong_khach;
    delete den_phong_ngu;
    delete dieu_hoa_phong_ngu;
    delete cam_phong_khach;
    delete cam_phong_ngu;
    delete khoa_cua_chinh;
    delete den_hien_nha;
    delete den_ban_cong;
    delete cam_san_vuon;
    delete tu_lanh;
    delete robot_hut_bui;
    delete may_giat;
    delete may_say;
    delete binh_nuoc_nong;
    delete tivi_phong_khach;
    delete he_thong_tuoi_cay;
    delete rem_cua_phong_ngu;
    delete rem_cua_phong_khach;
    delete may_loc_khong_khi;
    delete may_loc_nuoc;
    delete loa_am_thanh;
    delete cua_garage;
    delete lo_nuong;

    return 0;
}