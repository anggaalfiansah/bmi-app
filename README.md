# ScaleUp

ScaleUp adalah aplikasi berbasis C++ yang menggunakan WebView2 dan Crow sebagai backend. Proyek ini dikembangkan menggunakan Visual Studio dan menggunakan `vcpkg` sebagai package manager.

## Struktur Proyek

```
scaleup-fe/      # Project React untuk frontend
src/             # Source code utama aplikasi C++
  ├── templates/ # Hasil build frontend yang dicopy manual
  ├── bmi.cpp
  ├── bmi.h
  ├── main.cpp
  ├── resource.h
  ├── Resource.rc
  ├── scaleup_cli.cpp  # Prototype scaleup pertama
  ├── server.cpp
  ├── server.h
  ├── webview.cpp
  ├── webview.h
.gitignore
LICENSE
README.md
scaleup.sln
scaleup.vcxproj
scaleup.vcxproj.filters
scaleup.vcxproj.user
vcpkg.json       # Dependency package manager
```

## Persyaratan

- Windows 11 x64
- Visual Studio dengan toolset C++
- WebView2 SDK
- `vcpkg` untuk dependency management

## Instalasi Dependency

Semua dependency dikelola melalui `vcpkg`, namun saat pertama kali clone proyek, jalankan perintah berikut untuk menginstal semua package:

```sh
vcpkg install
```

## Build dan Run

Karena proyek ini sudah dikonfigurasi dalam Visual Studio:

1. Buka `scaleup.sln` di Visual Studio.
2. Pilih konfigurasi **Release x64**.
3. Build solusi.
4. Jalankan aplikasi dari Visual Studio.

## Fitur

- Aplikasi dapat dijalankan langsung di browser.
- Jika terhubung ke jaringan lokal, aplikasi dapat diakses dari perangkat lain dalam jaringan.
- Aplikasi berjalan di port **5000**.

## Catatan

- Dependency sudah dikonfigurasi dalam proyek Visual Studio, tetapi harus dijalankan `vcpkg install` saat pertama kali clone.
- Folder `src/templates` berisi hasil build frontend dan harus dicopy manual setelah build frontend selesai.
- Aplikasi menggunakan WebView2 untuk menampilkan UI berbasis web.

## Pembuat

**Angga Alfiansah** _(240101010032)_\
**Tessa Agustin** _(240101010039)_

## Untuk Keperluan

**Proyek Pengembangan Aplikasi**  
**SI103 - Struktur Data dan Algoritma**  
**Universitas Siber Asia**  
**Dosen Pengampu: Fesa Asy Syifa Nurul Haq, S.Kom, MMSI**

## 📸 Tampilan Aplikasi

### 🖥️ Desktop

![Beranda](https://raw.githubusercontent.com/anggaalfiansah/bmi-app/main/screenshoot/dekstop-home.png)
![Hasil Perhitungan](https://raw.githubusercontent.com/anggaalfiansah/bmi-app/main/screenshoot/dekstop-result.png)
![Tentang Aplikasi](https://raw.githubusercontent.com/anggaalfiansah/bmi-app/main/screenshoot/dekstop-about.png)

### 🌍 Web

![Beranda](https://raw.githubusercontent.com/anggaalfiansah/bmi-app/main/screenshoot/web-home.png)
![Hasil Perhitungan](https://raw.githubusercontent.com/anggaalfiansah/bmi-app/main/screenshoot/web-result.png)
![Tentang Aplikasi](https://raw.githubusercontent.com/anggaalfiansah/bmi-app/main/screenshoot/web-about.png)

### 📱 Mobile

| Beranda                                                                                                | Hasil Perhitungan                                                                                                  | Tentang Aplikasi                                                                                                 |
| ------------------------------------------------------------------------------------------------------ | ------------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------------- |
| ![Beranda](https://raw.githubusercontent.com/anggaalfiansah/bmi-app/main/screenshoot/mobile-home.jpeg) | ![Hasil Perhitungan](https://raw.githubusercontent.com/anggaalfiansah/bmi-app/main/screenshoot/mobile-result.jpeg) | ![Tentang Aplikasi](https://raw.githubusercontent.com/anggaalfiansah/bmi-app/main/screenshoot/mobile-about.jpeg) |
