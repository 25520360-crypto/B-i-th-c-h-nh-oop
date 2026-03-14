#include <iostream>
#include <cmath>

using namespace std;

// Cấu trúc phân số gồm Tử số và Mẫu số
struct Phanso{
    int Tu, Mau;
};

/*
 * Tính năng: Nhập dữ liệu tử số và mẫu số cho một phân số từ bàn phím.
 * Đầu vào: Biến tham chiếu a mang kiểu dữ liệu Phanso (truyền tham chiếu để lưu giá trị sau khi nhập).
 * Đầu ra: Không có (hàm void), nhưng biến a sẽ mang giá trị mới vừa nhập.
 */
void Nhap(Phanso &a){
    cin >> a.Tu >> a.Mau;
}

/*
 * Tính năng: Tìm Ước chung lớn nhất (ƯCLN) của 2 số nguyên dựa trên thuật toán Euclid. Dùng để hỗ trợ rút gọn phân số.
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
 * Tính năng: So sánh giá trị của 2 phân số, sau đó tìm và in phân số lớn hơn ra màn hình dưới dạng phân số đã rút gọn (Tử/Mẫu).
 * Đầu vào: 2 biến a và b mang kiểu dữ liệu Phanso (truyền tham trị vì chỉ cần dùng để tính toán và in ra).
 * Đầu ra: Không có (hàm void), nhưng sẽ in trực tiếp phân số lớn hơn (đã rút gọn) ra màn hình console.
 */
void Xuat(Phanso a, Phanso b){
    if((a.Tu * b.Mau) > (b.Tu * a.Mau))
        cout << a.Tu/UocLN(a.Tu, a.Mau) << "/"
             << a.Mau/UocLN(a.Tu, a.Mau);
    else
        cout << b.Tu/UocLN(b.Tu, b.Mau) << "/"
             << b.Mau/UocLN(b.Tu, b.Mau);
}

/*
 * Tính năng: Hàm khởi chạy chính của chương trình. Thực hiện khai báo 2 phân số, nhập liệu và gọi hàm xử lý xuất phân số lớn hơn.
 * Đầu vào: Không có.
 * Đầu ra: Trả về số nguyên 0 biểu thị chương trình kết thúc thành công.
 */
int main(){
    Phanso a, b;
    Nhap(a);
    Nhap(b);
    Xuat(a, b);
    return 0;
}
