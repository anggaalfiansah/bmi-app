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
        cout << "          ScaleUp\n";
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
    // Nama: Masukkan nama.
    // Tinggi Badan: Masukkan tinggi badan (cm).
    // Berat Badan: Masukkan berat badan (kg).
    // Usia: Masukkan usia (tahun).
    // Jenis Kelamin: Pilih jenis kelamin (Pria/Wanita).
    string nama;
    int tinggiBadan;
    int beratBadan;
    int usia;
    string jenisKelamin;
    string jenisKelaminChoice;

    cout << "\n--- Mode Single User ---\n";
    cout << "Masukan nama: ";
    cin >> nama;
    cout << "Masukkan tinggi badan (cm): ";
    cin >> tinggiBadan;
    // while (cin.fail() || (tinggiBadan < 1))
    // {
    //     cin.clear();            // Bersihkan flag error
    //     cin.ignore(1000, '\n'); // Abaikan input tidak valid
    //     cout << "Input tidak valid! masukan tinggi badan dalam bentuk angka: ";
    //     cin >> tinggiBadan;
    // }
    cout << "Masukkan berat badan (kg): ";
    cin >> beratBadan;
    // while (cin.fail() || (beratBadan < 1))
    // {
    //     cin.clear();            // Bersihkan flag error
    //     cin.ignore(1000, '\n'); // Abaikan input tidak valid
    //     cout << "Input tidak valid! masukan berat badan dalam bentuk angka: ";
    //     cin >> beratBadan;
    // }
    cout << "Masukkan usia (tahun): ";
    cin >> usia;
    // while (cin.fail() || (usia < 1))
    // {
    //     cin.clear();            // Bersihkan flag error
    //     cin.ignore(1000, '\n'); // Abaikan input tidak valid
    //     cout << "Input tidak valid! masukan usia dalam bentuk angka: ";
    //     cin >> usia;
    // }
    cout << "Pilih jenis kelamin (Pria/Wanita) p/w: ";
    cin >> jenisKelaminChoice;
    // Validasi input jenis kelamin
    while (cin.fail() || (jenisKelaminChoice != "w" && jenisKelaminChoice != "p"))
    {
        cin.clear();            // Bersihkan flag error
        cin.ignore(1000, '\n'); // Abaikan input tidak valid
        cout << "Input tidak valid! Silakan pilih antara p/w: ";
        cin >> jenisKelaminChoice;
    }
    if (jenisKelaminChoice == "w")
    {
        jenisKelamin = "wanita";
    }
    if (jenisKelaminChoice == "p")
    {
        jenisKelamin = "pria";
    }

    // Hitung BMI
    float tinggiBadanMeter = tinggiBadan / 100.0;
    float bmiScore = beratBadan / (tinggiBadanMeter * tinggiBadanMeter);

    // BMI STATUS
    // BMI < 18.5: Kurang berat badan. Disarankan untuk menambah berat badan.
    // 18.5 ≤ BMI < 24.9: Berat badan ideal. Pertahankan gaya hidup sehat.
    // 25 ≤ BMI < 29.9: Berat badan berlebih. Pertimbangkan diet dan olahraga.
    // BMI ≥ 30: Obesitas. Disarankan untuk berkonsultasi dengan dokter.
    string bmiStatus;
    string bmiSaran;

    if (bmiScore < 18.5)
    {
        bmiStatus = "Kurang berat badan";
        bmiSaran = "Disarankan untuk menambah berat badan";
    }
    if (bmiScore > 18.5 && bmiScore <= 24.9)
    {
        bmiStatus = "Berat badan ideal";
        bmiSaran = "Pertahankan gaya hidup sehat";
    }
    if (bmiScore > 24.9 && bmiScore <= 29.9)
    {
        bmiStatus = "Kurang berat berlebih";
        bmiSaran = "Pertimbangkan diet dan olahraga";
    }
    if (bmiScore > 30)
    {
        bmiStatus = "Obesitas";
        bmiSaran = "Disarankan untuk berkonsultasi dengan dokter";
    }

    cout << "Nama : " << nama << "\n";
    cout << "Tinggi Badan : " << tinggiBadan << " cm\n";
    cout << "Berat Badan : " << beratBadan << " kg\n";
    cout << "Usia : " << usia << " tahun\n";
    cout << "Jenis Kelamin : " << jenisKelamin << "\n";
    cout << "BMI Score : " << bmiScore << "\n";
    cout << "BMI Status : " << bmiStatus << "\n";
    cout << "Saran : " << bmiSaran << "\n";

    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore(); // Abaikan karakter sebelumnya
    cin.get();    // Tunggu input Enter
}

// Fungsi Mode Batch Processing
void aboutApplication()
{
    cout << "\n--- Tujuan Aplikasi ---\n";
    cout << "Aplikasi yang dirancang untuk membantu menghitung dan memantau status kesehatan tubuh dengan mudah dan akurat. Aplikasi ini membantu pengguna mengetahui apakah berat badan mereka termasuk kategori sehat, kelebihan, atau kekurangan berat badan berdasarkan tinggi dan berat badan yang dimasukkan.\n"; // Ganti dengan logika Batch Processing
    cout << "Tekan Enter untuk kembali ke menu utama...";
    cin.ignore(); // Abaikan karakter sebelumnya
    cin.get();    // Tunggu input Enter
}

// Fungsi Keluar
void exitApplication()
{
    cout << "\nTerima kasih telah menggunakan aplikasi BMI!\n";
}