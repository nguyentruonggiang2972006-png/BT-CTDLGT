#include <iostream>
#include <string>

using namespace std;

struct NhanVien {
    string maNhanVien;
    string hoTen;
    string ngaySinh;
    float luong;
};

void nhapNhanVien(NhanVien &nv) {
    cout << "Nhap ma nhan vien: ";
    cin >> nv.maNhanVien;
    cin.ignore();
    cout << "Nhap ho ten: ";
    getline(cin, nv.hoTen);
    cout << "Nhap ngay sinh (VD: 10/10/2000): ";
    getline(cin, nv.ngaySinh);
    cout << "Nhap luong (trieu dong): ";
    cin >> nv.luong;
}

void nhapDanhSach(NhanVien ds[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        nhapNhanVien(ds[i]);
    }
}

void xuatNhanVien(const NhanVien &nv) {
    cout << "Ma NV: " << nv.maNhanVien 
         << " | Ho ten: " << nv.hoTen 
         << " | Ngay sinh: " << nv.ngaySinh 
         << " | Luong: " << nv.luong << " trieu dong" << endl;
}

void xuatDanhSach(NhanVien ds[], int n) {
    for (int i = 0; i < n; ++i) {
        xuatNhanVien(ds[i]);
    }
}

void bubbleSort(NhanVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i; j--) {
            if (ds[j].luong < ds[j - 1].luong) {
                NhanVien temp = ds[j];
                ds[j] = ds[j - 1];
                ds[j - 1] = temp;
            }
        }
    }
}

void timKiemNhiPhan(NhanVien ds[], int n, float X) {
    int left = 0, right = n - 1;
    bool found = false;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (
