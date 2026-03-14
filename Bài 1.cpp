#include <iostream>
#include <cmath>

using namespace std;

// Cấu trúc phân số gồm Tử số và Mẫu số
struct Phanso{
    int Tu, Mau;
};

/*
 * Tính năng: Nhập dữ liệu tử số và mẫu số cho một phân số từ bàn phím.
 * Đầu vào: Biến tham chiếu a mang kiểu dữ liệu Phanso (tham chiếu để thay đổi giá trị gốc).
 * Đầu ra: Không có (hàm void), nhưng biến a sẽ mang giá trị mới vừa nhập.
 */
void Nhap(Phanso &a){
    cin >> a.Tu >> a.Mau;
}

/*
 * Tính năng: Tìm Ước chung lớn nhất (ƯCLN) của 2 số nguyên dựa trên thuật toán Euclid. Dùng để hỗ trợ rút gọn phân số.
 * Đầu vào: 2 số nguyên a và b (đại diện cho tử số và mẫu số).
 * Đầu ra: Trả về một số nguyên là giá trị Ước chung lớn nhất của a và b.
 */
int UocLN(int a, int b){
    a = abs(a);
    b = abs(b);
    if(b == 0) return a;
    return UocLN(b, a%b);
}

/*
 * Tính năng: Rút gọn và xuất phân số ra màn hình theo định dạng "Tử/Mẫu".
 * Đầu vào: Biến a mang kiểu dữ liệu Phanso (truyền tham trị vì chỉ cần in ra, không cần sửa đổi gốc).
 * Đầu ra: Không có (hàm void), nhưng sẽ in trực tiếp kết quả ra màn hình console.
 */
void Xuat(Phanso a){
    cout << a.Tu/UocLN(a.Tu, a.Mau) << "/"
         << a.Mau/UocLN(a.Tu, a.Mau);
}

/*
 * Tính năng: Hàm khởi chạy chính của chương trình. Thực hiện khai báo phân số, gọi hàm nhập và xuất.
 * Đầu vào: Không có.
 * Đầu ra: Trả về số nguyên 0 biểu thị chương trình kết thúc thành công.
 */
int main(){
    Phanso a, b;
    Nhap(a);
    Xuat(a);
    return 0;
}
