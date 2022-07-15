# Kalkulator-Sederhana

 Kalkulator dengan input seperti 1 + 2 + 3 * 4 . Semua angka dan operator dipisah oleh tanda spasi. Disini saya menggunakan 
cara stack, namun sebelum itu saya membuat input tersebut agar dihilangkan tanda spasinya, 
sehingga menjadi 1+2+3*4 . Cara tersebut saya gunakan dengan cara menghitung panjang 
string, lalu mendeteksi tempat tanda spasi, dan kemudian dihapuskan. 

 Setelah dihapuskan, bentuk tersebut nampak seperti bentuk infix, dimana disini saya 
mendapat ide bahwa bisa saja diubah ke bentuk postfix lalu dihitung dengan menggunakan 
stack. Pertama tama, ubah bentuk infix ke postfix, sehingga dapat berbentuk menjadi 
12+34*+ . Disitu artinya angka 1 dan 2 ditambahkan, dan angka 3 dan 4 dikalikan. 
Setelah itu barulah hasil dari keduanya ditambahkan, sehingga didapatkan nilai 15 sebagai 
hasilnya. 

![LampiranOutputProgram](https://user-images.githubusercontent.com/93639634/178755297-6fa716f7-10ae-49b5-96ad-eff2b3b84b1e.png)
