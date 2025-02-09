#ifndef SERVER_H
#define SERVER_H

/**
 * @brief Memulai server HTTP menggunakan Crow.
 * 
 * Fungsi ini akan menginisialisasi dan menjalankan server web berbasis Crow.
 * Server akan menangani request untuk halaman utama dan API perhitungan BMI.
 * 
 * - Menyediakan endpoint `/` untuk menampilkan halaman web.
 * - Menyediakan endpoint `/api/bmi` untuk perhitungan BMI.
 * - Menggunakan middleware CORS untuk mengizinkan akses lintas domain.
 * - Berjalan pada port 5000 dengan dukungan multi-threading.
 */
void StartServer();

#endif // SERVER_H
