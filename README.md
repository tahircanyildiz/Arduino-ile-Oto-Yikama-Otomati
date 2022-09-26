# Arduino-ile-Oto-Yikama-Otomati
Arduino kullanarak oto yıkamalarda bulunan bakiye yükleme ve yüklenen bakiye ile işlem yapmak için geliştirilen proje 
****************************************************************************************************************************************

Projede bizden istenen, fiziksel ortamda Arduino kartı ile proje dokümanında belirtilen isterleri karşılayan bir uygulama geliştirmektir. Ardino, elektronik ile iligli olan her insanın kolayca kullanabilmesi için geliştirilmiş açık kaynaklı bir mikrokontrolcüplatformudur.Arduino,  wiring ta-banlı programlama dili ile programlanır ve processing tabanlı Arduino yazılım geliştirme ortamı olan Arduino IDE ile karta aktarılır.  Arduino kullanarak çeşitli sensörlerden gelen sinyalleri okuyabilir, ışık yakıp söndürebilir, motor çalıştırabilir; kısacası aklınıza gelebilecek tüm elektronik uygulamaları yapabilirsiniz.
Tasarlayacağımız devrede 6 adet buton , 1 adet LCD display , 1 adet breadboard , 1 adet potansiyometre ,1 adet Arduino UNO kartı ,yeteri kadar direnç ve jumper kablo kullanılmıştır.
Geliştirlen projenin amacı kısaca şöyledir;

1- İlk başta LCD display üzerinde “Hoşgeldiniz…” ve ardından  “Bakiye giriniz…” yazısı yazmaktadır. 

2- Butonların işlevi için 2 adet mod tasarlanmıştır. 1.mod ile butonların işlevi bakiye yüklemektir. 1.mod ile butonların işlevi hizmet seçimidir.

3- 1.modda butonlar ile soldan sağa doğru 5TL,10TL,20TL,50TL ve 100TL yüklemesi yapılır ve 6.butona basarak bakiye yüklemesi tamamlanarak 2.moda geçilir.

4-	2.mod ile LCD displaye “işlem seçiniz..” yazısı yazdırlır. Sonrasında sırasıyla; “1)Köpükleme”,”2)Yıkama”,”3)Kurulama” ve “4)Cilalama “ yazdırılıp kullanıcıdan yapılmasını istediği işlemleri seçmesi beklenir.Eğer kullanıcı yaptığı işlemlerde yanlışlık yaptığını düşünüyorsa 6.butona basarak seçimlerini resetleyip seçim ekranına baştan başlayabilir.

5-	Kullanıcı seçim yaptıkça malzeme sayısı güncellenir ve bakiye güncellenir.Eğer yapmak istediği işlem için parası yetmiyorsa LCD display üzerinde “Yetersiz Bakiye” uyarısı yazacaktır.Eğer yapmak istediği işlemde malzeme tükendiyse LCD display üzerinde “Yetersiz Malzeme” uyarısı yazacaktır.

6-	Kullanıcı yaptığı seçimlerden sonra 5.butona basarak onay verecektir ve ardından programtarafından  1 ile 4 arasında rastgele bir sayı oluşturulacaktır.Eğer oluşturulan random sayı 2 ise “Para Sıkıştı” uyarısı verip işlemleri resetlemesi istenecektir.Bunun için 6.butona basması istenecektir ve 6.butona bastığında para iadesi yapılacak, yaptığı işlemler sıfırlanacak ve bakiye yükleme ekranına geri dönülecektir.

7-	Oluşan sayı 2’den farklı ise LCD display üzerinde  “işlemler Yapıldı” yazacaktır.

8-	Yapılan işlemler sonunda kalan bakiyesi ekrana yazdırılacaktır.

9-	Kasada olan paralara göre para üstü en az banknot ile verilecektir.

10-	Para üstü verildikten sonra tekrar 1.moda dönülecektir ve “Hoşgeldiniz..”,”Bakiye giriniz..” yazdırılıp en başa dönüp yeni müşteri üzerinden işlem yapılacaktır.
