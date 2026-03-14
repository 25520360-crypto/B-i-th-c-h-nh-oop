#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Cấu trúc HSSV dùng để lưu trữ thông tin của một Học sinh/Sinh viên
struct HSSV{
    char Name[100];
    float DiemToan, DiemVan;
};

/*
 * Tính năng: Nhập thông tin của học sinh/sinh viên bao gồm: Họ tên, Điểm Toán và Điểm Văn từ bàn phím.
 * Đầu vào: Biến tham chiếu a mang kiểu dữ liệu HSSV (dùng tham chiếu & để lưu lại thông tin vừa nhập vào biến gốc).
 * Đầu ra: Không có (hàm void), nhưng biến a sẽ mang các giá trị (Tên, Điểm Toán, Điểm Văn) vừa được nhập.
 */
void Nhap(HSSV &a){
    cin.getline(a.Name, 100); // Nhập chuỗi ký tự (họ tên) có thể chứa khoảng trắng, tối đa 99 ký tự
    cin >> a.DiemToan >> a.DiemVan; // Nhập điểm Toán và điểm Văn
}

/*
 * Tính năng: Tính điểm trung bình cộng của Toán và Văn, sau đó in tên và điểm trung bình ra màn hình
 *            (điểm trung bình được làm tròn 2 chữ số thập phân).
 * Đầu vào: Biến a mang kiểu dữ liệu HSSV (truyền tham trị, chỉ lấy dữ liệu ra để tính toán và in).
 * Đầu ra: Không có (hàm void), in trực tiếp chuỗi "Tên [tab] Điểm Trung Bình" ra màn hình console.
 */
void Xuat(HSSV a){
    float DTB;
    DTB = (a.DiemToan + a.DiemVan) / 2; // Tính điểm trung bình

    cout << a.Name << "\t"
         << fixed << setprecision(2) << DTB;
}

/*
 * Tính năng: Hàm khởi chạy chính của chương trình. Khai báo biến lưu trữ HSSV, gọi hàm nhập liệu và xuất kết quả.
 * Đầu vào: Không có.
 * Đầu ra: Trả về số nguyên 0 biểu thị chương trình kết thúc thành công mà không có lỗi.
 */
int main(){
    HSSV a;
    Nhap(a);
    Xuat(a);
    return 0;
}
