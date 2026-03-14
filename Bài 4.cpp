#include <iostream>
#include <cmath>

using namespace std;

// Cấu trúc Date dùng để lưu trữ thông tin ngày, tháng, năm
struct Date {
    int day, month, year;
};

/*
 * Tính năng: Nhập dữ liệu ngày, tháng, năm từ bàn phím.
 * Đầu vào: Biến tham chiếu a mang kiểu dữ liệu Date (dùng tham chiếu & để lưu lại giá trị nhập vào).
 * Đầu ra: Không có (hàm void), nhưng biến a sẽ mang giá trị ngày tháng năm vừa nhập.
 */
void Nhap(Date &a) {
    cin >> a.day >> a.month >> a.year;
}

/*
 * Tính năng: Trả về số ngày tối đa trong một tháng của một năm cụ thể. Có kiểm tra năm nhuận chuẩn xác cho tháng 2.
 * Đầu vào: 2 biến số nguyên: month (tháng) và year (năm).
 * Đầu ra: Trả về một số nguyên là tổng số ngày của tháng đó (28, 29, 30 hoặc 31).
 */
int Songaytungthang(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;

        case 2:
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
                return 29;
            }
            return 28;
        default:
            return 30;
    }
}

/*
 * Tính năng: Tìm ngày tiếp theo (ngày mai) dựa vào ngày hiện tại và in kết quả ra màn hình.
 * Đầu vào: Biến a mang kiểu dữ liệu Date (truyền tham trị để tính toán và in ra mà không làm thay đổi biến gốc ở main).
 * Đầu ra: Không có (hàm void), in trực tiếp ngày/tháng/năm tiếp theo ra màn hình console.
 */
void Nextday(Date a) {
    // Nếu ngày hiện tại nhỏ hơn số ngày tối đa của tháng -> Chỉ việc cộng thêm 1 ngày
    if (a.day < Songaytungthang(a.month, a.year)) {
        a.day++;
    }
    else {
        // Nếu là ngày cuối tháng -> Reset về ngày 1 và cộng thêm 1 tháng
        a.day = 1;
        a.month++;

        // Nếu cộng tháng mà vượt quá 12 -> Reset về tháng 1 và cộng thêm 1 năm
        if (a.month > 12) {
            a.month = 1;
            a.year++;
        }
    }

    // In kết quả
    cout << a.day << "/" << a.month << "/" << a.year;
}

/*
 * Tính năng: Hàm khởi chạy chính của chương trình. Khai báo biến cấu trúc Date, gọi hàm nhập liệu và hàm tìm ngày tiếp theo.
 * Đầu vào: Không có.
 * Đầu ra: Trả về số nguyên 0 biểu thị chương trình kết thúc thành công.
 */
int main() {
    Date a;
    Nhap(a);
    Nextday(a);
    return 0;
}
