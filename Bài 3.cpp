#include <iostream>
#include <cmath>

using namespace std;

// Cấu trúc phân số gồm Tử số (Tu) và Mẫu số (Mau)
struct Phanso{
    int Tu, Mau;
};

/*
 * Tính năng: Nhập dữ liệu tử số và mẫu số cho một phân số từ bàn phím.
 * Đầu vào: Biến tham chiếu a mang kiểu dữ liệu Phanso (tham chiếu & để lưu lại giá trị sau khi nhập).
 * Đầu ra: Không có (hàm void), nhưng biến a sẽ mang giá trị mới vừa nhập.
 */
void Nhap(Phanso &a){
    cin >> a.Tu >> a.Mau;
}

/*
 * Tính năng: Tìm Ước chung lớn nhất (ƯCLN) của 2 số nguyên dựa trên thuật toán Euclid. Phục vụ cho việc rút gọn phân số ở bước cuối.
 * Đầu vào: 2 số nguyên a và b.
 * Đầu ra: Trả về một số nguyên là giá trị Ước chung lớn nhất của a và b.
 */
int UocLN(int a, int b){
    a = abs(a);
    b = abs(b);
    if(b == 0) return a;
    return UocLN(b, a%b);
}

/*
 * Tính năng: Nhập một ký tự phép toán (+, -, *, /) từ bàn phím. Dựa vào ký tự đó để thực hiện phép tính tương ứng
 *            giữa 2 phân số. Sau đó rút gọn phân số kết quả và in ra màn hình định dạng "Tử/Mẫu".
 * Đầu vào: 2 biến a và b mang kiểu dữ liệu Phanso (truyền tham trị, biến a được dùng làm biến trung gian lưu kết quả).
 * Đầu ra: Không có (hàm void), in trực tiếp phân số kết quả (đã rút gọn) ra màn hình console.
 */
void Xuat(Phanso a, Phanso b){
    char c;
    cin >> c; // Nhập phép toán

    // Xử lý tính toán dựa trên phép toán được nhập
    switch(c){
        case '+': // Cộng 2 phân số: (a/b) + (c/d) = (a*d + c*b) / (b*d)
            a.Tu = a.Tu*b.Mau + b.Tu*a.Mau;
            a.Mau = a.Mau*b.Mau;
            break;
        case '-': // Trừ 2 phân số: (a/b) - (c/d) = (a*d - c*b) / (b*d)
            a.Tu = a.Tu*b.Mau - b.Tu*a.Mau;
            a.Mau = a.Mau*b.Mau;
            break;
        case '*': // Nhân 2 phân số: (a/b) * (c/d) = (a*c) / (b*d)
            a.Tu = a.Tu*b.Tu;
            a.Mau = a.Mau*b.Mau;
            break;
        case '/': // Chia 2 phân số: (a/b) / (c/d) = (a*d) / (b*c)
            a.Tu = a.Tu*b.Mau;
            a.Mau = a.Mau*b.Tu;
            break;
    }

    // Xuất kết quả đã được rút gọn chia cho ƯCLN
    cout << a.Tu/UocLN(a.Tu, a.Mau) << "/"
         << a.Mau/UocLN(a.Tu, a.Mau);
}

/*
 * Tính năng: Hàm khởi chạy chính của chương trình. Thực hiện khai báo 2 phân số, gọi hàm nhập liệu
 *            và gọi hàm xử lý tính toán kiêm xuất kết quả.
 * Đầu vào: Không có.
 * Đầu ra: Trả về số nguyên 0 biểu thị chương trình kết thúc thành công mà không có lỗi.
 */
int main(){
    Phanso a, b;
    Nhap(a);
    Nhap(b);
    Xuat(a,b);
    return 0;
}
