*This project has been created as part of the 42 curriculum by ukuruder, mueruslu.*

# push_swap

## Description
push_swap projesinin amacı, verilen tam sayı dizisini yalnızca izin verilen stack operasyonlarını kullanarak artan sıraya getirmektir.
Bu repoda iki bağlı liste (stack a ve stack b) üzerinde çalışan bir sıralama programı geliştirildi. Hedef, sadece doğru sıralamak değil; aynı zamanda mümkün olduğunca az operasyon üretmektir.

Projede:
- Girdi parse edilir (tek argümanda boşluklu giriş dahil).
- Geçersiz karakter, taşma (INT sınırları), duplicate gibi durumlar hata ile sonlandırılır.
- Değerler indexleme (scaling) ile normalize edilir.
- Veri boyutu ve düzensizlik oranına göre farklı stratejiler kullanılır.

## Instructions
### Compilation
- Makefile kullanımı:
  - make
  - make clean
  - make fclean
  - make re

### Execution
- Temel kullanım:
  - ./push_swap 2 1 3 6 5 8
  - ./push_swap "3 2 1 6 5"

- Strateji flag’leri:
  - --simple   : küçük girdiler için basit yaklaşım
  - --medium   : chunk tabanlı orta seviye yaklaşım
  - --complex  : radix tabanlı yaklaşım
  - --adaptive : düzensizlik oranına göre otomatik strateji seçimi (varsayılan)

- Benchmark çıktısı:
  - --bench flag’i ile stderr’e toplam operasyon ve operasyon dağılımı yazdırılır.
  - Örnek:
    - ./push_swap --adaptive --bench 4 1 3 2 9 7 8

### Input Rules
- Yalnızca geçerli int değerler kabul edilir.
- Aynı sayı birden fazla kez girilemez.
- Hatalı inputta program Error yazarak çıkar.

## Algorithm Design and Justification
Bu projede tek bir algoritma yerine adaptif çoklu-strateji tercih edildi. Gerekçe: push_swap’ta her veri dağılımı için tek bir yöntem en iyi sonucu vermez.

### 1) Ön işleme: Scaling (Indexleme)
- Her düğüme, kendisinden küçük kaç eleman olduğu bilgisi atanır (index).
- Böylece gerçek değer büyüklüklerinden bağımsız, 0..n-1 aralığında güvenli karşılaştırma yapılır.
- Özellikle radix/chunk gibi yöntemlerde operasyon kararlarını sadeleştirir.

Neden seçildi?
- Taşma riski azaltılır.
- Bit tabanlı ve aralık tabanlı stratejiler için ortak bir temsil sağlar.

### 2) SIMPLE stratejisi (küçük boyut, düşük düzensizlik)
- Boyut 2 ise swap.
- Boyut 3 için özel durum kuralları (minimum hamleyle sıralama).
- Daha büyük küçük setlerde minimum elemanlar b’ye taşınır, a’da 3’lü sıralama yapılır, sonra pa ile geri alınır.

Neden seçildi?
- Küçük n için sabit/çok düşük hamle maliyeti vardır.
- Daha karmaşık algoritmaların overhead’ini taşımaz.

### 3) MEDIUM stratejisi (chunk tabanlı)
- a’dan b’ye gönderimde index aralıklarına göre chunk mantığı uygulanır.
- Chunk aralığı pratikte `range ≈ 1.42 * sqrt(n)` olacak şekilde ayarlanır.
- Slider (kayan pencere) mantığı kullanılır: a’dan b’ye her push sonrası a’nın boyutu 1 azalırken aktif aralık ileri kayar.
- Bu nedenle efektif range her adımda genişleyerek/ilerleyerek sıradaki uygun elemanları daha hızlı yakalar.
- Üstten gelen eleman index’e göre doğrudan push veya push+rotate kararı alır.
- b’den a’ya dönüşte en büyük index eleman en az rotate/reverse rotate ile tepeye getirilir.

Neden seçildi?
- Orta boyutlu veride operasyon sayısını pratikte ciddi düşürür.
- a küçüldükçe kayan range’in adaptif ilerlemesi gereksiz rotate sayısını azaltır ve toplam hamleyi iyileştirir.
- Tam radix’e göre bazı dağılımlarda daha verimli hamle üretebilir.

### 4) COMPLEX stratejisi (Binary Radix)
- Index değerleri bit bit işlenir.
- i’inci bit 1 ise ra, 0 ise pb uygulanır.
- Her bit turu sonunda b’deki elemanlar pa ile geri alınır.

Neden seçildi?
- Büyük n için öngörülebilir ve stabil bir davranış verir.
- Operasyon sayısı ölçeklendikçe güvenilir performans sağlar.

### 5) ADAPTIVE strateji seçimi
Program inversion tabanlı bir düzensizlik oranı hesaplar:
- mistakes / total_pairs

Seçim eşikleri:
- disorder < 0.2  -> simple
- 0.2 <= disorder < 0.5 -> medium
- disorder >= 0.5 -> complex

Neden seçildi?
- Neredeyse sıralı veride ağır algoritmalar gereksizdir.
- Karışıklık arttıkça daha güçlü yöntemlere geçerek toplam hamle optimize edilir.

## Complexity Overview
- SIMPLE: pratikte küçük n için düşük maliyet, genel yaklaşım O(n²) karakterinde
- MEDIUM (chunk): yaklaşık O(n√n) pratik davranış hedefi
- COMPLEX (radix): O(n log n) davranış

Not: MEDIUM stratejisindeki `1.42` çarpanı yalnızca sabit katsayıdır; bu nedenle asimptotik sınıfı değiştirmez. `1.42 * sqrt(n)` ile `sqrt(n)` aynı Big-O sınıfındadır; yani Big-O sınıfı değişmez. Bu ayar sadece pratik performans tuning’i sağlar.


## Resources
### Classic References
- 42 push_swap subject ve intra dokümantasyonu
- C standard library (man pages): malloc, free, write
- Linked list temel yaklaşımları ve iki stack ile sıralama üzerine klasik kaynaklar
- Radix sort ve inversion count (algorithm design references)

### AI Usage Disclosure
Bu projede AI araçları yalnızca destek amaçlı kullanıldı:
- Kullanım alanları:
  - README metninin yapılandırılması ve dil iyileştirmesi
  - Algoritma açıklamalarının daha okunabilir hale getirilmesi
  - Dokümantasyon taslağı için section önerileri
- AI’nin kullanılmadığı alanlar:
  - Temel algoritma kararı ve implementasyonun ana geliştirme süreci
  - Operasyon fonksiyonlarının kodlanması
  - Parse, hata yönetimi, veri yapısı mantığı

Özetle AI, üretim kodunun yerine geçmedi; dokümantasyon ve açıklama kalitesini artırmak için yardımcı araç olarak kullanıldı. Mimari yapı ve algoritma tercihi bize ait.

## Authors
- ukuruder
- mueruslu
