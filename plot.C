    #include <TFile.h>
    #include <TTree.h>
    #include <TCanvas.h>
    #include <TH1F.h>
    #include <iostream>
    #include <string>
    #include "TROOT.h"
    #include "TApplication.h"
    void plot(int fileNumber) {
    // 构造文件名
    
    gROOT->Reset();
    std::string sourceFile = "data00" + std::to_string(fileNumber) + ".root";
    //std::string sourceFile = std::format("data{:04d}.root", fileNumber);
    // 打开ROOT文件
    TFile *file = TFile::Open(sourceFile.c_str());
    if (!file || file->IsZombie()) {
    std::cout << "Error: Could not open ROOT file!" << std::endl;
    return;
    }

    // 获取树（TTree）
    TTree *tree = (TTree*)file->Get("tree");
    if (!tree) {
    std::cout << "Error: Could not find tree in the file!" << std::endl;
    return;
    }

    // 创建一个画布并将其分成2行4列
    TCanvas *c1 = new TCanvas("c1", "ADC Plots", 200, 10, 700, 900);
    c1->Divide(2, 4); // 将画布分成2行4列

    // 创建直方图对象，用于绘制图形
    // 这里我们为每个图像创建一个新的直方图对象，避免多个图形覆盖
    TH1F *h1[8]; // 用一个数组来存储8个直方图对象

    // 为每个图形创建不同的直方图对象
    for (int i = 0; i < 8; i++) {
    h1[i] = new TH1F(Form("h%d", i+1), Form("ADC Histogram %d", i+1), 2000, 200, 4200); // 2000, 200, 4200 是直方图的bin数和范围
    }

    // 绘制8个图，每个图在不同的子画布区域
    c1->cd(1);
    tree->Draw("adc[0][8] >> h1[0](2000,200,4200)", "", ""); // 绘制到h1[0]
    c1->GetPad(1)->SetLogy(1);
    c1->cd(2);
    tree->Draw("adc[0][10] >> h1[1](2000,200,4200)", "", ""); // 绘制到h1[1]
    c1->GetPad(2)->SetLogy(1);
    c1->cd(3);
    tree->Draw("adc[0][12] >> h1[2](2000,200,4200)", "", ""); // 绘制到h1[2]
    c1->GetPad(3)->SetLogy(1);
    c1->cd(4);
    tree->Draw("adc[0][14] >> h1[3](2000,200,4200)", "", ""); // 绘制到h1[3]
    c1->GetPad(4)->SetLogy(1);
    c1->cd(5);
    tree->Draw("adc[1][25] >> h1[4](2000,200,4200)", "", ""); // 绘制到h1[4]
    c1->GetPad(5)->SetLogy(1);
    c1->cd(6);
    tree->Draw("adc[1][27] >> h1[5](2000,200,4200)", "", ""); // 绘制到h1[5]
    c1->GetPad(6)->SetLogy(1);
    c1->cd(7);
    tree->Draw("adc[1][29] >> h1[6](2000,200,4200)", "", ""); // 绘制到h1[6]
    c1->GetPad(7)->SetLogy(1);
    c1->cd(8);
    tree->Draw("adc[1][31] >> h1[7](2000,200,4200)", "", ""); // 绘制到h1[7]
    c1->GetPad(8)->SetLogy(1);
    //c1->Modified(); // 标记画布已修改
    c1->Update(); // 更新画布
if (!c1)
    file->Close();
    }


