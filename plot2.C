#include <TFile.h>
#include <TTree.h>
#include <TCanvas.h>
#include <TH1F.h>
#include <iostream>
#include <string>
#include "TApplication.h"

void plot2(int fileNumber1,int fileNumber2) {
    // 构造文件名
    TString sourceFile1 = TString::Format("data_C2_%04d_%04d.root", fileNumber1, fileNumber1);

    // 打开ROOT文件
    TFile *file = TFile::Open(sourceFile1);
    if (!file || file->IsZombie()) {
        std::cout << "Error: Could not open ROOT file!" << std::endl;
        return;
    }

    // 获取树（TTree）
    TTree *tree = (TTree*)file->Get("tree");
    if (!tree) {
        std::cout << "Error: Could not find tree in the file!" << std::endl;
        file->Close();
        return;
    }

    // 创建画布并分成2行4列
    TCanvas *c1 = new TCanvas("c1", "ADC Plots", 200, 10, 700, 900);
    c1->Divide(2, 4);

    // 创建直方图
    TH1F *h1[8]; // 用数组存储8个直方图对象
    for (int i = 0; i < 8; i++) {
        h1[i] = new TH1F(Form("h%d", i + 1), Form("8 detectors Histogram %d", i + 1), 1200,0,120000);
    }

    // 逐个子画布绘制直方图
    c1->cd(1);
    tree->Draw("evte*4.058285425+89.85398331>>h1[0](1200,0,120000)", "cid==1&&sid==2&&ch==0");
    //c1->GetPad(1)->SetLogy(1);//c1->Update();

    c1->cd(2);
    tree->Draw("evte*4.045473635+49.11079527>>h1[1](1200,0,120000)", "cid==1&&sid==2&&ch==1");
    //c1->GetPad(2)->SetLogy(1);

    c1->cd(3);
    tree->Draw("evte*3.817484437+52.61287677>>h1[2](1200,0,120000)", "cid==1&&sid==2&&ch==2");
    //c1->GetPad(3)->SetLogy(1);

    c1->cd(4);
    tree->Draw("evte*3.848993177+61.20152669>>h1[3](1200,0,120000)", "cid==1&&sid==2&&ch==3");
    //c1->GetPad(4)->SetLogy(1);

    c1->cd(5);
    tree->Draw("evte*3.916995556+52.0534274>>h1[4](1200,0,120000)", "cid==1&&sid==2&&ch==4");
    //c1->GetPad(5)->SetLogy(1);

    c1->cd(6);
    tree->Draw("evte*4.065870103+31.87540479>>h1[5](1200,0,120000)", "cid==1&&sid==2&&ch==5");
    //c1->GetPad(6)->SetLogy(1);

    c1->cd(7);
    tree->Draw("evte*4.070053983+18.43799465>>h1[6](1200,0,120000)", "cid==1&&sid==2&&ch==6");
    //c1->GetPad(7)->SetLogy(1);

    c1->cd(8);
    tree->Draw("evte*3.876732107+120.9769>>h1[7](1200,0,120000)", "cid==1&&sid==2&&ch==7");
    //c1->GetPad(8)->SetLogy(1);
    
    
    std::cout << "000" << std::endl;
    
    /////////////////////////// sourceFile2
    TString sourceFile2 = TString::Format("data_C2_%04d_%04d.root", fileNumber2, fileNumber2);

    // 打开ROOT文件
    TFile *file2 = TFile::Open(sourceFile2);
    if (!file2 || file2->IsZombie()) {
        std::cout << "Error: Could not open ROOT file!" << std::endl;
        return;
    }
    std::cout << "001" << std::endl;
    // 获取树（TTree）
    TTree *tree2 = (TTree*)file2->Get("tree");
    if (!tree2) {
        std::cout << "Error: Could not find tree in the file!" << std::endl;
        file2->Close();
        return;
    }

    // 创建画布并分成2行4列
    //TCanvas *c1 = new TCanvas("c1", "ADC Plots", 200, 10, 700, 900);
    //c1->Divide(2, 4);

    // 创建直方图
    TH1F *h2[8]; // 用数组存储8个直方图对象
    for (int i = 0; i < 8; i++) {
        h2[i] = new TH1F(Form("h%d", i + 1), Form("8 detectors Histogram %d", i + 1), 1200,0,120000);
        
    }

    // 逐个子画布绘制直方图
    c1->cd(1);
    tree2->Draw("evte*4.058285425+89.85398331>>h2[0](1200,0,120000)", "cid==1&&sid==2&&ch==0", "same");
    h2[0] = (TH1F*)gDirectory->Get("h2[0]");
    h2[0] -> SetLineColor(kRed);
    h2[0]->Scale(2);
    h2[0]->Draw("same");
    h2[0]->Draw("HIST same");
    //c1->GetPad(1)->SetLogy(1);//c1->Update();

    c1->cd(2);
    tree2->Draw("evte*4.045473635+49.11079527>>h2[1](1200,0,120000)", "cid==1&&sid==2&&ch==1", "same");
    //c1->GetPad(2)->SetLogy(1);
    h2[1] = (TH1F*)gDirectory->Get("h2[1]");
    h2[1] -> SetLineColor(kRed);
    h2[1]->Scale(2);
    h2[1]->Draw("same");
    h2[1]->Draw("HIST same");

    c1->cd(3);
    tree2->Draw("evte*3.817484437+52.61287677>>h2[2](1200,0,120000)", "cid==1&&sid==2&&ch==2", "same");
    //c1->GetPad(3)->SetLogy(1);
    h2[2] = (TH1F*)gDirectory->Get("h2[2]");
    h2[2] -> SetLineColor(kRed);
    h2[2]->Scale(2);
    h2[2]->Draw("same");
    h2[2]->Draw("HIST same");

    c1->cd(4);
    tree2->Draw("evte*3.848993177+61.20152669>>h2[3](1200,0,120000)", "cid==1&&sid==2&&ch==3", "same");
    //c1->GetPad(4)->SetLogy(1);
    h2[3] = (TH1F*)gDirectory->Get("h2[3]");
    h2[3] -> SetLineColor(kRed);
    h2[3]->Scale(2);
    h2[3]->Draw("same");
    h2[3]->Draw("HIST same");

    c1->cd(5);
    tree2->Draw("evte*3.916995556+52.0534274>>h2[4](1200,0,120000)", "cid==1&&sid==2&&ch==4", "same");
    //c1->GetPad(5)->SetLogy(1)
    h2[4] = (TH1F*)gDirectory->Get("h2[4]");
    h2[4] -> SetLineColor(kRed);
    h2[4]->Scale(2);
    h2[4]->Draw("same");
    h2[4]->Draw("HIST same");

    c1->cd(6);
    tree2->Draw("evte*4.065870103+31.87540479>>h2[5](1200,0,120000)", "cid==1&&sid==2&&ch==5", "same");
    //c1->GetPad(6)->SetLogy(1);
    h2[5] = (TH1F*)gDirectory->Get("h2[5]");
    h2[5] -> SetLineColor(kRed);
    h2[5]->Scale(2);
    h2[5]->Draw("same");
    h2[5]->Draw("HIST same");

    c1->cd(7);
    tree2->Draw("evte*4.070053983+18.43799465>>h2[6](1200,0,120000)", "cid==1&&sid==2&&ch==6", "same");
    //c1->GetPad(7)->SetLogy(1);
    h2[6] = (TH1F*)gDirectory->Get("h2[6]");
    h2[6] -> SetLineColor(kRed);
    h2[6]->Scale(2);
    h2[6]->Draw("same");
    h2[6]->Draw("HIST same");

    c1->cd(8);
    tree2->Draw("evte*3.876732107+120.9769>>h2[7](1200,0,120000)", "cid==1&&sid==2&&ch==7", "same");
    h2[7] = (TH1F*)gDirectory->Get("h2[7]");
    h2[7] -> SetLineColor(kRed);
    h2[7]->Scale(2);
    h2[7]->Draw("same");
    h2[7]->Draw("HIST same");
    //c1->GetPad(8)->SetLogy(1);
    std::cout << "002" << std::endl;

    // 更新画布
    c1->Update();
    //file->Close(); // 关闭文件
}

