#include <iostream>
#include <string>
using namespace std;

// BAGIAN 1: STRUKTUR DATA GLOBAL ("DATABASE")

const int MAX_USERS = 100; //buat user maksimal sebnyak 100, hrus psti krena array statis

// array global untuk Data Pengguna (menggunakan Parallel Array)
string users[MAX_USERS];        // menyimpan username
string passwords[MAX_USERS];    // menyimpan password
int userRoles[MAX_USERS];       // 0 untuk Nasabah, 1 buat Admin
double userPoints[MAX_USERS];   // untuk menyimpan saldo poin
int userCount = 0;              // counter jumlah user saat ini (sebagai pencatat user skarang ada brapa)


// BAGIAN 2

// membuat akun admin, sekaligus agar sistem tidak kosong
void inisialisasiData() {
    // Membuat Akun Admin Default pada Index 0
    users[0] = "admin";
    passwords[0] = "admin123";
    userRoles[0] = 1;       // 1 menandakan peran Admin
    userPoints[0] = 0;
    
    // Set counter menjadi 1 karena sudah ada 1 akun
    userCount = 1; 
    
    cout << "[SYSTEM] Data berhasil diinisialisasi. Admin default dibuat." << endl;
}

// registerNasabah
void registerNasabah() {
    // 1. Cek Kapasitas Array (agar tidak overflow)
    if (userCount >= MAX_USERS) {
        cout << "Error: Database penuh! Tidak bisa menambah pengguna baru." << endl;
        return;
    }

    string newName, newPass;
    
    cout << "\n--- REGISTRASI NASABAH BARU ---" << endl;
    cout << "Masukkan Username: ";
    cin >> newName;
    
    // opsional: Di sini bisa ditambah validasi apakah username sudah ada
    
    cout << "Masukkan Password: ";
    cin >> newPass;

    // 2. Simpan ke Array Global pada index 'userCount'
    users[userCount] = newName;
    passwords[userCount] = newPass;
    userRoles[userCount] = 0; // 0 menandakan Nasabah
    userPoints[userCount] = 0; // Saldo awal 0

    // 3. Inkrementasi Counter
    userCount++;

    cout << "Registrasi berhasil! Silakan login." << endl;
}

// Fungsi login
// Return: Index pengguna (jika sukses) atau -1 (jika gagal)
int login() {
    string inputUser, inputPass;
    
    cout << "\n--- LOGIN SISTEM ---" << endl;
    cout << "Username: ";
    cin >> inputUser;
    cout << "Password: ";
    cin >> inputPass;

    // Logika Linear Search (Mencari kecocokan data)
    for (int i = 0; i < userCount; i++) {
        // Cek username DAN password pada index yang sama
        if (users[i] == inputUser && passwords[i] == inputPass) {
            return i; // Login Sukses, kembalikan index pengguna
        }
    }

    return -1; // Login Gagal, data tidak ditemukan
}

// ==========================================
// BAGIAN 3: MENU PENGGUNA (PLACEHOLDER)
// ==========================================

// Menu untuk Nasabah (Role 0)
void userMenu(int index) {
    // Parameter 'index' digunakan untuk mengambil data spesifik pengguna tersebut
    cout << "\n========================================" << endl;
    cout << "Selamat Datang, " << users[index] << " (Nasabah)" << endl;
    cout << "Saldo Poin Anda: " << userPoints[index] << endl;
    cout << "========================================" << endl;
    cout << "[NOTE: Menu Transaksi akan dibuat di Minggu 2]" << endl;
    
    // Simulasi logout
    cout << "Tekan Enter untuk logout...";
    cin.ignore(); cin.get();
}

// Menu untuk Admin (Role 1)
void adminMenu(int index) {
    cout << "\n========================================" << endl;
    cout << "PANEL ADMIN - User: " << users[index] << endl;
    cout << "Total User Terdaftar: " << userCount << endl;
    cout << "========================================" << endl;
    cout << "[NOTE: Menu Kelola Barang akan dibuat di Minggu 2]" << endl;
    
    // Simulasi logout
    cout << "Tekan Enter untuk logout...";
    cin.ignore(); cin.get();
}

// ==========================================
// BAGIAN 4: PROGRAM UTAMA (MAIN LOOP)
// ==========================================

int main() {
    // Langkah 1: Siapkan Data
    inisialisasiData();
    
    int pilihan;
    
    // Loop Utama Aplikasi
    while (true) {
        cout << "\n=== ECOVOLT E-WASTE BANK (MINGGU 1) ===" << endl;
        cout << "1. Login" << endl;
        cout << "2. Registrasi Nasabah" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            // Proses Login
            int loggedInIndex = login();
            
            if (loggedInIndex != -1) {
                // Login Berhasil -> Cek Role untuk routing menu
                int role = userRoles[loggedInIndex];
                
                if (role == 1) {
                    adminMenu(loggedInIndex);
                } else {
                    userMenu(loggedInIndex);
                }
            } else {
                cout << "Login Gagal! Username atau password salah." << endl;
            }
            
        } else if (pilihan == 2) {
            // Proses Register
            registerNasabah();
            
        } else if (pilihan == 3) {
            cout << "Terima kasih telah menggunakan EcoVolt." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}
