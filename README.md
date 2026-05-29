
# PASS‑Server
Windows 平台轻量级原生 C++ 静态网页服务器，无第三方依赖
Lightweight native C++ static web server for Windows, zero third‑party dependencies.

## 概述 / Overview
PASS‑Server 是基于纯 C++ 编写的简易静态文件服务器，适配 Windows 系统。程序首次运行会自动生成配置目录与网站目录，可正确解析网页资源，解决浏览器直接下载文件问题。
PASS‑Server is a simple static file server written in pure C++ for Windows. It automatically generates configuration and website directories on first run, and correctly parses web resources to avoid browser file‑download behavior.

## 功能特性 / Features
- 自动创建 conf、www 目录与默认配置文件
  Auto‑create conf/, www/ directories and default configuration
- 自动生成默认 index.html 欢迎首页
  Auto‑generate default index.html welcome page
- 支持静态资源：HTML、CSS、JS、PNG、JPG、GIF
  Serve static resources: HTML, CSS, JS, PNG, JPG, GIF
- 开启目录自动浏览功能（autoindex）
  Auto directory listing (autoindex)
- 标准 HTTP 错误页面：403 禁止访问、404 页面不存在
  Standard HTTP error pages: 403 Forbidden, 404 Not Found
- 完善 MIME 类型识别，浏览器直接渲染网页，不会下载文件
  Complete MIME‑type recognition for direct browser rendering
- 单可执行文件，部署简单便捷
  Single executable file, easy to deploy

## 编译环境 / Build Environment
- MinGW‑w64
- Windows 10 / Windows 11

## 编译命令 / Compile Command
```bash
g++ main.cpp pass_socket.cpp fs_utils.cpp config.cpp -o PASS-Server.exe -lws2_32
 
 
运行程序 / Run
 
1. 编译得到 PASS‑Server.exe
2. 双击运行程序，自动生成目录结构
3. 保持控制台窗口打开，服务器持续运行
 
访问地址 / Access
 
浏览器打开以下地址访问网页
Open in browser:
 
plaintext
  
http://127.0.0.1:8080
 
 
自动生成目录结构 / Auto‑Generated Structure
 
plaintext
  
./
├── PASS‑Server.exe      # 主程序 Main program
├── conf/
│   └── server.conf      # 配置文件 Configuration file
└── www/
    └── index.html       # 默认首页 Default homepage
 
 
配置说明（conf/server.conf）/ Configuration
 
plaintext
  
listen 8080;
root "./www";
autoindex on;
 
 
- listen：监听端口号 Listening port number
- root：网站根目录 Website root directory
- autoindex on/off：开启/关闭目录浏览 Enable or disable directory listing
 
网站部署 / Website Deployment
 
将所有网页文件（HTML、CSS、JS、图片）放入 www 文件夹，服务器会自动读取并提供访问。
 
支持文件类型 / Supported File Types
 
- .html / .htm
- .css
- .js
- .png
- .jpg / .jpeg
- .gif
 
