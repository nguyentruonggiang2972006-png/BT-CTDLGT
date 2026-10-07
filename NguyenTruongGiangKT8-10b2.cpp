#include <iostream>
#include <iomanip>

using namespace std;

struct NhanVien {
    char maNV[20];
    char hoTen[50];
    char ngaySinh[15];
    float luong;
};

void nhapDanhSach(NhanVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---" << endl;
        cout << "Nhap ma NV: ";
        cin >> ds[i].maNV;
        
        cin.ignore(); 
        
        cout << "Nhap ho ten: ";
        cin.getline(ds[i].hoTen, 50);
        
        cout << "Nhap ngay sinh (dd/mm/yyyy): ";
        cin.getline(ds[i].ngaySinh, 15);
        
        cout << "Nhap luong (trieu dong): ";
        cin >> ds[i].luong;
    }
}

void xuatNhanVien(NhanVien nv) {
    cout << "Ma NV: " << nv.maNV 
         << " | Ho ten: " << nv.hoTen 
         << " | Ngay sinh: " << nv.ngaySinh 
         << " | Luong: " << fixed << setprecision(2) << nv.luong << " trieu dong" << endl;
}

void xuatDanhSach(NhanVien ds[], int n) {
    for (int i = 0; i < n; i++) {
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
    int left = 0;
    int right = n - 1;
    int found_index = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (ds[mid].luong == X) {
            found_index = mid;
            break; 
        }
        
        if (ds[mid].luong < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (found_index != -1) {
        cout << "\n---> Tim thay nhan vien co luong = " << X << ":" << endl;
        
        int i = found_index;
        while (i >= 0 && ds[i].luong == X) {
            i--;
        }
        i++; 
        
        while (i < n && ds[i].luong == X) {
            xuatNhanVien(ds[i]);
            i++;
        }
    } else {
        cout << "\n---> Khong tim thay nhan vien nao co luong = " << X << endl;
    }
}

int main() {
    int n;
    cout << "Nhap so luong nhan vien n = ";
    cin >> n;
    
    NhanVien ds[100]; 
    
    nhapDanhSach(ds, n);
    cout << "\n=== DANH SACH NHAN VIEN VUA NHAP ===" << endl;
    xuatDanhSach(ds, n);
    
    bubbleSort(ds, n);
    cout << "\n=== DANH SACH SAU KHI SAP XEP TANG DAN THEO LUONG ===" << endl;
    xuatDanhSach(ds, n);
    
    float X;
    cout << "\nNhap muc luong X can tim: ";
    cin >> X;
    timKiemNhiPhan(ds, n, X);
    
    return 0;
}
