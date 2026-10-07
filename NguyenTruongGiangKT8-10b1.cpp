#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct KhachHang {
    int maKH;
    char tenKH[50];
    char sdt[15];
    float tongTien;
};

void nhapDanhSach(KhachHang ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin khach hang thu " << i + 1 << " ---" << endl;
        cout << "Nhap ma KH: ";
        cin >> ds[i].maKH;
        
        cin.ignore(); 
        
        cout << "Nhap ten KH: ";
        cin.getline(ds[i].tenKH, 50);
        
        cout << "Nhap so dien thoai: ";
        cin.getline(ds[i].sdt, 15);
        
        cout << "Nhap tong tien thanh toan: ";
        cin >> ds[i].tongTien;
    }
}

void xuatKhachHang(KhachHang kh) {
    cout << "Ma KH: " << kh.maKH 
         << " | Ten KH: " << kh.tenKH 
         << " | SDT: " << kh.sdt 
         << " | Tong tien: " << fixed << setprecision(2) << kh.tongTien << endl;
}

void xuatDanhSach(KhachHang ds[], int n) {
    for (int i = 0; i < n; i++) {
        xuatKhachHang(ds[i]);
    }
}

void insertionSort(KhachHang ds[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang key = ds[i];
        int j = i - 1;
        
        while (j >= 0 && ds[j].tongTien > key.tongTien) {
            ds[j + 1] = ds[j];
            j = j - 1;
        }
        ds[j + 1] = key;
    }
}

void timKiemNhiPhan(KhachHang ds[], int n, float X) {
    int left = 0;
    int right = n - 1;
    int found_index = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (ds[mid].tongTien == X) {
            found_index = mid;
            break; 
        }
        
        if (ds[mid].tongTien < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (found_index != -1) {
        cout << "\n---> Tim thay khach hang co tong tien = " << X << ":" << endl;
        
        int i = found_index;
        while (i >= 0 && ds[i].tongTien == X) {
            i--;
        }
        i++; 
        
        while (i < n && ds[i].tongTien == X) {
            xuatKhachHang(ds[i]);
            i++;
        }
    } else {
        cout << "\n---> Khong tim thay khach hang nao co tong tien = " << X << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong khach hang n = ";
    cin >> n;
    
    KhachHang ds[100]; 
    
    nhapDanhSach(ds, n);
    cout << "\n=== DANH SACH KHACH HANG VUA NHAP ===" << endl;
    xuatDanhSach(ds, n);
    
    insertionSort(ds, n);
    cout << "\n=== DANH SACH SAU KHI SAP XEP TANG DAN THEO TONG TIEN ===" << endl;
    xuatDanhSach(ds, n);
    
    float X;
    cout << "\nNhap tong tien X can tim: ";
    cin >> X;
    timKiemNhiPhan(ds, n, X);
    
    return 0;
}
