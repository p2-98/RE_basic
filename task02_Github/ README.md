### Tìm hiểu hoạt động của Github
> Tài liệu tham khảo : [Github](https://github.com/hocchudong/git-github-for-sysadmin).
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 12.10.2016
>

----

[1. Giới thiệu sơ lược về Git và Github](#introduce)

- [1.1 Git và Github là gì?](#concept)
- [1.2 Tại sao nên sử dụng Git?](#benefit)

[2. Các thao tác với Github](#usegit)

- [2.1 Thao tác trên Linux](#linux)
-	[2.1.1 Cài đặt trên Linux](#setupLinux)
-	[2.1.2 Các thao tác với Git trên Linux](#useLinux)
- [2.2 Thao tác trên Windowns](#windows)
-	[2.2.1 Cài đặt phần mềm Github](#setupGithub)
-	[2.2.2 Các thao tác trên phần mềm Github](#usewindows)
- [2.3 Tạo một SSH Key](#sshkey)

----

<a name ="introduce"> </a>

##1. Giới thiệu sơ lược về Git và Github:

<a name ="concept"> </a>

###1.1 Git và Github là gì?

Git là gì?

-	Git là tên gọi của một Hệ thống quản lý phiên bản phân tán (Distributed Version Control System – DVCS) là một trong những hệ thống quản lý phiên bản phân tán phổ biến nhất hiện nay. DVCS nghĩa là hệ thống giúp mỗi máy tính có thể lưu trữ nhiều phiên bản khác nhau của một mã nguồn được nhân bản (clone) từ một kho chứa mã nguồn (repository), mỗi thay đổi vào mã nguồn trên máy tính sẽ có thể ủy thác (commit) rồi đưa lên máy chủ nơi đặt kho chứa chính. Và một máy tính khác (nếu họ có quyền truy cập) cũng có thể clone lại mã nguồn từ kho chứa hoặc clone lại một tập hợp các thay đổi mới nhất trên máy tính kia. Trong Git, thư mục làm việc trên máy tính gọi là Working Tree.
-	Ngoài ra, có một cách hiểu khác về Git đơn giản hơn đó là nó sẽ giúp bạn lưu lại các phiên bản của những lần thay đổi vào mã nguồn và có thể dễ dàng khôi phục lại dễ dàng mà không cần copy lại mã nguồn rồi cất vào đâu đó.
-	Cơ chế lưu trữ phiên bản của Git là nó sẽ tạo ra một “ảnh chụp” (snapshot) trên mỗi tập tin và thư mục sau khi commit, từ đó nó có thể cho phép bạn tái sử dụng lại một ảnh chụp nào đó mà bạn có thể hiểu đó là một phiên bản. Đây cũng chính là lợi thế của Git so với các DVCS khác khi nó không “lưu cứng” dữ liệu mà sẽ lưu với dạng snapshot.

Github là gì? [Github](http://github.com)

-	Git là tên gọi của một mô hình hệ thống. Các máy tính có thể clone lại mã nguồn từ một repository và [Github](http://github.com) chính là một dịch vụ máy chủ repository (Repo) công cộng, mỗi người có thể tạo tài khoản trên đó để tạo ra các kho chứa của riêng mình để có thể làm việc.

<a name ="benefit"> </a>

###1.2 Tại sao nên sử dụng Git?

Có rất nhiều lợi thế để bạn nên sử dụng Git trong việc lập trình ngay từ hôm nay, bất kể là lập trình cái gì đi chăng nữa.

-	Git dễ sử dụng, an toàn và nhanh chóng.
-	Có thể giúp quy trình làm việc code theo nhóm đơn giản hơn rất nhiều bằng việc kết hợp các phân nhánh (branch).
-	Bạn có thể làm việc ở bất cứ đâu vì chỉ cần clone mã nguồn từ kho chứa hoặc clone một phiên bản thay đổi nào đó từ kho chứa, hoặc một nhánh nào đó từ kho chứa.
-	Dễ dàng trong việc deployment sản phẩm.
-	Và nhiều hơn thế nữa.

<a name ="usegit"> </a>

##2. Các thao tác với Github

- Add: Tạo một Repo mới
- Remove: Xoá Repo
- Commit: Xác nhận thực hiện lệnh
- Push: Đồng bộ lên Git
- Pull: Cập nhật lại những thay đổi mà bạn đã thực hiện
- Fetch: Tìm kiếm và truy xuất toàn bộ dữ liệu từ máy chủ
- Clone: Tạo bản sao
- Fork: Các nhánh trong project
- Star & Watch: Truy cập dữ liệu

<a name ="linux"> </a>

###2.1 Thao tác trên Linux

<a name = "setupLinux"> </a>

####2.1.1 Cài đặt trên Linux

Với OS là Ubuntu

>apt-get install git

Với OS là Fedora, Centos

>yum instal git

Các thiết lập ban đầu

- Bạn cần thiết lập tên và email của mình để mỗi khi commit lên server sẽ nhận biết được ai commit lên vì một repo có thể có nhiều người tham gia.

Ex:

>git config --global user.name "Duc NC"
>
>git config --global user.email nguyencongduc3112@gmail.com

- Lựa chọn trình soạn thảo mặc định, có thể là vi, vim, nano,...

Ex:

>git config --global core.editor vi

- Liệt kê các thiết lập:

>git config --list

Liên kết với tài khoản github bằng SSH

>ssh-keygen -t rsa

`
Enter file in which to save the key (/root/.ssh/id_rsa): [Press enter]
Enter passphrase (empty for no passphrase): [Press enter]
Enter same passphrase again: [Press enter]
Your identification has been saved in /root/.ssh/id_rsa.
Your public key has been saved in /root/.ssh/id_rsa.pub.`

- Nếu bạn nhập passphrase thì hãy nhớ pass này!

- Kết quả:

>ls ~/.ssh/

`id_rsa       id_rsa.pub   known_hosts`

>ssh-agent -s
>
>ssh-add ~/.ssh/id_rsa
>
>cat ~/.ssh/id_rsa.pub

copy đoạn mã này
Truy cập đường dẫn sau https://github.com/settings/ssh (đảm bảo bạn đã đăng nhập vào github), chọn Add SSH key, đặt tên cho key này tại `Title` và paste nội dung vừa copy vào ô `Key`
<img src ="http://i.imgur.com/O8Yebax.png">
Lúc này bạn đã có thể commit lên github tại máy local mà không cần nhập username và password.

<a name = "useLinux"> </a>

####2.1.2 Các thao tác với Git trên Linux

**- Tạo mới**

Tạo một repo mới trên trang github.com

<img src="http://i.imgur.com/aRhTGmq.png">
<img src="http://i.imgur.com/8PS63aS.png">

**- Clone**

Clone repo đó về bằng một trong các cách sau:

*Linux*

SSH: `git clone git@github.com:ducnc92/demo1.git`

hoặc: `git clone git@github.com:ducnc92/demo1.git /opt/demo` để clone vào thư mục /opt/demo

đối với phương pháp này các bạn cần nhập passphrase của ~/.ssh/id_rsa (có thể không cần nếu bạn không đặt passphrase)

HTTPS: `git clone https://github.com/ducnc92/demo1.git`

hoặc: `git clone https://github.com/ducnc92/demo1.git /opt/demo` để clone vào thư mục /opt/demo

Để lấy các link SSH, HTTPS này ta làm như sau: Click vào các hyperlink HTTPS hoặc SSH rồi click Copy to clipboard.

<img src="http://i.imgur.com/feafdMA.png">

Ở đây tôi sử dụng lệnh `git clone git@github.com:ducnc92/demo1.git`

Lúc này trong thư mục hiện tại sẽ có thêm thư mục demo1 chứa các file trong repo trên github.

Chuyển vào thư mục này:

> cd demo1/
>
> ls

Lúc này sẽ thấy trong thư mục này có file `README.md`. Để sửa file này ta có thể sử dụng bất cứ trình soạn thảo nào, chẳng hạn vi, nano, gedit,...

> vi README.md

Thêm vào nội dung như sau:
`
Xin chao!
Toi la Ducnc.`
Tạo một thư mục mới, chẳng hạn tên là script để chứa các script của tôi.

>mkdir script

Tạo một script mới trong thư mục đó.

>vi script/script1.sh

`#!/bin/sh
echo "Hello Python Vietnam"
sleep 10`
bằng cách tương tự các bạn có thể tạo thêm nhiều thư mục, file hướng dẫn, cấu hình, script,... tùy ý

**Add, Commit, Push**

Để thực hiện hành động `add` ta sử dụng lệnh sau

>git add README.md để add file README.md

hoặc `git add *` để add tất cả các file hiện có.

Để thự hiện hành động commit file README.md ta thực hiện lệnh

>git commit README.md

hoặc `git commit *` để commit tất cả.

ta nên thêm tham số -m để ghi lại một comment cho hành động đó

>git commit README.md -m "ducnc sua doi"

Lúc này các thay đổi của bạn đã được lưu lại trên máy cục bộ. Để đồng bộ lên server Github ta thực hiện lệnh:

>git push origin master

=> nhập passphrase (nếu bạn đặt passphrase ở mục 1.1.) với phương pháp clone ssh hoặc nhập username, password nếu clone bằng https

<img src="http://i.imgur.com/u3NhK0Q.png">

Lúc này trở lại trang github.com và xem `repo script` lúc đầu sẽ thấy các commit của ta đã được đẩy lên.

<img src="http://i.imgur.com/uUTsyHX.png">

Một cách khác nếu bạn không muốn thực hiện clone về máy như bước trên thì bạn có thể làm như sau:

- Tạo một repo mới trên github.com mà không tạo file README.md (giả sử ở đây là repo demo2)

- Tại máy local tạo một thư mục để chứa repo mới này. Ví dụ:

>mkdir /opt/demo2
>
>cd /opt/demo2

Thực hiện tạo các file, thư mục như ý muốn. Sau đó thực hiện add, commit, push tương tự như trên Nhưng ở đây cần thêm lệnh `git remote add origin $git-url` trước khi push. Tham khảo ví dụ sau:

>vi README.md
>
>git add README.md
>
>git commit README.md

hoặc `git commit README.md -m noi dung`

>git remote add origin git@github.com:ducnc92/demo2.git
>
>git push origin master

Sau đó nhập passphrase(nếu cần) hoặc username + password (nếu sử dụng SSH)

**Pull**

Giả sử trên server github của bạn có những thay đổi mà máy local chưa cập nhật những thay đổi đó. Bạn thực hiện lệnh sau:

>cd cd /opt/demo1/
>
>git pull

<a name ="windows"> </a>

###2.2 Thao tác trên Windows

<a name ="setupGithub"> </a>

####2.2.1 Cài đặt phần mềm Gitthub:

Download tại địa chỉ: https://windows.github.com/

Cài đặt bình thường, yêu cầu phải có .NET 4.5

Giao diện của chương trình:

<img src="http://i.imgur.com/itnGJ0E.png">

Thêm tài khoản Github:

- Click vào tool and options (hình bánh răng cạnh biểu tượng Sync) chọn options, Add account. Khai báo username và password trên github.

- Tại mục Configure git thêm Tên và email của mình

<img src="http://i.imgur.com/PG0LDAk.png">

Click Update

<a name ="usewindows"> </a>

####2.2.2 Các thao tác trên phần mềm Github

*Tạo repo mới*

Tạo repo trên github.com tự như mục 2.1.1.

Tạo repo bằng phần mềm Github

- Click vào dấu cộng, chọn tab Create, đặt tên và chọn đường dẫn cho repo mới

<img src="http://i.imgur.com/Teh28iC.png">

- Tuy nhiên repo mới sinh ra mới chỉ có ở máy trạm, tại mục `Other`. Chọn chuột phải vào repo đó và chọn `Open in Explorer` để sửa nội dung của repo này.

<img src="http://i.imgur.com/oXrGcww.png">

- Sau khi chỉnh sửa xong, để đẩy repo đó lên github.com ta click vào `Publish this repository` và thực hiện như hình sau. Chú ý cần chọn Organization đặt repo này.

<img src="http://i.imgur.com/lDvXPLm.png">

*Clone*

Click vào dấu cộng, chọn tab Clone, lựa chọn tổ chức mong muốn và chọn repo cần clone

<img src="http://i.imgur.com/9fjPGOj.png">

Để chỉnh sửa nội dung của repo này ta chọn chuột phải vào nó và chọn `Open in Explorer`

<img src="http://i.imgur.com/9pFBEY7.png">

Lúc đó chương trình Windows Explorer sẽ mở ra thư mục chứa repo của github, bạn có thể chỉnh sửa các file trong này, tạo xóa thư mục,... một cách bình thường.

*Add, commit, push, pull*

Trở lại với chương trình Github ta sẽ thấy dòng `uncommited changes` tại repo ta vừa sửa. Bạn hãy điền vào đó comment và ấn `commit to master`

<img src="http://i.imgur.com/6l1KX2O.png">

Lúc này sự thay đổi của bạn với mã nguồn đã được ghi lại trên máy local, để đồng bộ nó lên server github bạn hãy ấn vào biểu tượng `Sync` ở góc trên cùng bên phải.

Sau khi đồng bộ xong, quay trở lại repo trên trang github.com.

<img src="http://i.imgur.com/249DH0K.png">

Để đồng bộ những thay đổi trên github.com về máy local (pull) ta cũng click vào biểu tượng `Sync` như bên trên.

<a name = "sshkey"> </a>

####2.3 Tạo một SSH Key mới

> *Tạo một SSH Key*:
>

- **Bước 1:** Mở Git Bash
- **Bước 2:** Copy đoạn code dưới đây, thay vào địa chỉ email của bạn GitHub.
`$ ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
Generating public/private rsa key pair.`
- **Bước 3:** Ấn Enter để lưu vào địa chỉ tập tin mặc định
`Enter a file in which to save the key (/Users/you/.ssh/id_rsa): [Press enter]`
- **Bước 4:** Nhập vào mật khẩu. Thông tin sẽ hiện ở "[Working with SSH key passphrases](https://help.github.com/articles/working-with-ssh-key-passphrases/)".
`Enter passphrase (empty for no passphrase): [Type a passphrase]
Enter same passphrase again: [Type passphrase again]`

> *Chèn SSH Key vào ssh - agent*
>

- Trước khi tạo một SHH Key mới bạn hãy kiểm tra xem [SHH Key đã được cài đặt](https://help.github.com/articles/checking-for-existing-ssh-keys/) hay chưa và tạo SHH Key mới

- Nếu bạn sử dụng Github cho Windows bạn có thể tạo ra một bản sao Repo mà không cần SHH Keys
* Chèn SHH Key *

- **Bước 1:** Nhập vào một SHH Keys khả dụng
*Nếu bạn sử dụng Git Bash, hãy bật shh -agent và nhập vào đoạn code*
`# start the ssh-agent in the background
$ eval "$(ssh-agent -s)"
Agent pid 59566`
* Nếu bạn sử dụng một công cụ khác, điển hình như Git for Windows, hãy bật shh -agent và nhập vào đoạn code:*
`# start the ssh-agent in the background
eval $(ssh-agent -s)
Agent pid 59566`
- **Bước 2:** Chèn SSH Keys của bạn vào shh -agent. Nếu đã tồn tại một SSH Keys thay về tạo một SSH Key mới bạn cần thay thế *id_rsa* trong command với tên riêng mà bạn đã tạo trước đó
`$ ssh-add ~/.ssh/id_rsa`
- **Bước 3:** Chèn SSH Keys vào tài khoản Github của bạn.

###Hết
