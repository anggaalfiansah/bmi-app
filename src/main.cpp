#include <iostream>
#include <string>
#include <cstdlib> // Untuk system("cls") atau system("clear") jika diperlukan

using namespace std;

// Deklarasi fungsi-fungsi
void singleUserMode();
void aboutApplication();
void exitApplication();

int main()
{
    int choice;
    do
    {
        // Bersihkan layar (opsional)
        #ifdef _WIN32
                system("cls"); // Untuk Windows
        #else
                system("clear"); // Untuk Linux/Mac
        #endif
        // Menu Utama
        cout << "=====================================\n";
        cout << "          Aplikasi BMI\n";
        cout << "=====================================\n";
        cout << "1. Mode Single User\n";
        cout << "2. Tujuan Aplikasi\n";
        cout << "3. Keluar\n";
        cout << "=====================================\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        // Validasi input menu
        while (cin.fail() || choice < 1 || choice > 3)
        {
            cin.clear();            // Bersihkan flag error
            cin.ignore(1000, '\n'); // Abaikan input tidak valid
            cout << "Input tidak valid! Silakan pilih antara 1-3: ";
            cin >> choice;
        }

        // Eksekusi pilihan menu
        switch (choice)
        {
        case 1:
            singleUserMode();
            break;
        case 2:
            aboutApplication();
            break;
        case 3:
            exitApplication();
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (choice != 3);

    return 0;
}

// Fungsi Mode Single User
void singleUserMode()
{
    cout << "\n--- Mode Single User ---\n";
    cout << "Fitur ini belum diimplementasikan.\n"; // Ganti dengan logika Single User
    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore(); // Abaikan karakter sebelumnya
    cin.get();    // Tunggu input Enter
}

// Fungsi Mode Batch Processing
void aboutApplication()
{
    cout << "\n--- Tujuan Aplikasi ---\n";
    cout << "Membantu pengguna menghitung BMI dan memberikan rekomendasi kesehatan berdasarkan hasil perhitungan\n"; // Ganti dengan logika Batch Processing
    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore(); // Abaikan karakter sebelumnya
    cin.get();    // Tunggu input Enter
}

// Fungsi Keluar
void exitApplication()
{
    cout << "\nTerima kasih telah menggunakan aplikasi BMI!\n";
}
