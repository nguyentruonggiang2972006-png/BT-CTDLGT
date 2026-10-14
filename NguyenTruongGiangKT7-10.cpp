#include <iostream>
#include <string>

using namespace std;

struct KhachHang {
    int maKhachHang;
    string tenKhachHang;
    string soDienThoai;
    float tongTienThanhToan;
};

void nhapKhachHang(KhachHang &kh) {
    cout << "Nhap ma khach hang: ";
    cin >> kh.maKhachHang;
    cin.ignore();
    cout << "Nhap ten khach hang: ";
    getline(cin, kh.tenKhachHang);
    cout << "Nhap so dien thoai: ";
    getline(cin, kh.soDienThoai);
    cout << "Nhap tong tien thanh toan: ";
    cin >> kh.tongTienThanhToan;
}

void nhapDanhSach(KhachHang ds[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "\n--- Nhap thong tin khach hang thu " << i + 1 << " ---" << endl;
        nhapKhachHang(ds[i]);
    }
}

void xuatKhachHang(const KhachHang &kh) {
    cout << "Ma KH: " << kh.maKhachHang 
         << " | Ten KH: " << kh.tenKhachHang 
         << " | SDT: " << kh.soDienThoai 
         << " | Tong tien: " << kh.tongTienThanhToan << endl;
}

void xuatDanhSach(KhachHang ds[], int n) {
    for (int i = 0; i < n; ++i) {
        xuatKhachHang(ds[i]);
    }
}

void insertionSort(KhachHang ds[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang key = ds[i];
        int j = i - 1;

        while (j >= 0 && ds[j].tongTienThanhToan > key.tongTienThanhToan)
