/*
  Cotton - Competitive Quiz Button System
  Team: FCC (Foursma Computer Club) - SMA Negeri 4 Denpasar
  Period: January-February 2024
  
  Repository: github.com/username/cotton-quiz-buzzer
  
  Team Roles:
  - Main Engineer: Dendy Fajar Kurniawan (Hardware design, relay circuit, AC-DC interfacing)
  - Main Programmer: Arasel Bezaleel Thenilo (Firmware development, algorithm)
  - Main Designer: Nizar Heyden Susilo (Enclosure design)
  - Team Leader: Nayaka Alkaesyah Suryanto (Project management)
  - Video Editor: Bijan Ramadhan Aditri
  
  Description:
  Arduino-based lockout buzzer system for 3-player quiz competitions.
  Features relay-based 220V AC buzzer integration and modular RJ11 connectivity.
  
  Based on original project documentation: Laporan_COTTON.pdf
*/

// Deklarasi variabel untuk simpan pin 
// setiap komponen dan informasi penting 

// Bagian Reset Button 
const int pinBuzzer = 7; 
const int pinTombolReset = 6;

// Bagian Player Button 
const int jumlahPeserta = 3; 
const int pinLedPeserta[] = {12, 10, 8}; 
const int pinTombolPeserta[] = {13, 11, 9};

void setup(){ 
  // Pertama, kita deklarasikan terlebih dahulu mode apa bagi setiap pin 
  pinMode(pinBuzzer, OUTPUT); 
  pinMode(pinTombolReset, INPUT_PULLUP); 
  
  for(int i = 0; i < jumlahPeserta; i++){
    pinMode(pinLedPeserta[i], OUTPUT);
  } 
  
  for(int i = 0; i < jumlahPeserta; i++){
    pinMode(pinTombolPeserta[i], INPUT_PULLUP);
  }

  // Kedua, atur agar semua LED para peserta awalnya dalam posisi mati 
  for(int i = 0; i < jumlahPeserta; i++){
    digitalWrite(pinLedPeserta[i], LOW);
  }

  while(digitalRead(pinTombolReset) == HIGH){}
  // Kita tunggu sampai tombol reset ditekan untuk memulai pengecekan awal

  // Hitung mundur, 3, 2, 1 
  // pinBuzzer = HIGH, buzzer akan nyala 
  // pinBuzzer = LOW, buzzer akan mati 
  // Karena buzzer terhubung dengan relay pada port NO (Normally Open) 
  for(int i = 0; i < 3; i++){ 
    digitalWrite(pinBuzzer, HIGH); 
    delay(500); 
    digitalWrite(pinBuzzer, LOW); 
    delay(500); 
  }

  int durasi = 300; 
  bool selesaiCek = false;

  // Seperti animasi kecil saat program baru dimulai
  // Akan berhenti setelah tombol reset ditekan 
  while(selesaiCek == false){ 
    for(int i = 0; i < jumlahPeserta; i++){ 
      digitalWrite(pinLedPeserta[i], HIGH); 
      digitalWrite(pinBuzzer, HIGH); 
      delay(durasi); 
      digitalWrite(pinBuzzer, LOW); 
      digitalWrite(pinLedPeserta[i], LOW);

      if(digitalRead(pinTombolReset) == LOW){ 
        selesaiCek = true; 
        break; 
      } 
    }

    if(durasi > 25){
      durasi -= 25;
    }
    // Semakin lama, semakin cepat lampu LED akan bergantian nyala 
  } 
}

void loop(){ 
  int yangTekanPertama = -1;

  // Cek semua tombol peserta 
  for(int i = 0; i < jumlahPeserta; i++){ 
    if(digitalRead(pinTombolPeserta[i]) == LOW){
      yangTekanPertama = i;
    } 
  }

  // Jika ada peserta yang telah tekan tombol 
  // Lampu peserta akan bernyala, dan hanya dapat dihentikan 
  // dengan ditekannya tombol reset 
  if(yangTekanPertama != -1){ 
    digitalWrite(pinLedPeserta[yangTekanPertama], HIGH);
    digitalWrite(pinBuzzer, HIGH); 
    delay(500); 
    digitalWrite(pinBuzzer, LOW);

    while(digitalRead(pinTombolReset) == HIGH){}

    digitalWrite(pinLedPeserta[yangTekanPertama], LOW); 
  } 
}
