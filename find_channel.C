#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>
#include <string>


std::string detectors[] = {"sid==2&&ch==1", "sid==2&&ch==4", "sid==2&&ch==9", "sid==2&&ch==14", "sid==3&&ch==3", "sid==3&&ch==8", "sid==3&&ch==11", "sid==3&&ch==14", "sid==4&&ch==3", "sid==4&&ch==6", "sid==4&&ch==9", "sid==4&&ch==14", "sid==5&&ch==3", "sid==5&&ch==8", "sid==5&&ch==11", "sid==5&&ch==14"};   

double gausPeak[16], gausWidth[16];
void find_channel(int fileNumber) {
    // 打开ROOT文件
    //TFile *file = TFile::Open("data_C1_0252_wave.root");

    std::string soureFile = "data_C1_0" + std::to_string(fileNumber) + "_wave.root";

    // 打开ROOT文件
    TFile *file = TFile::Open(soureFile.c_str());
    
    // 获取树
    TTree *tree = (TTree*)file->Get("tree");  // 假设树的名字是 "tree"
    if (!tree) {
        std::cerr << "Error getting tree" << std::endl;
        file->Close();
        return;
    }
 
// 绘制直方图
for (int i=0;i<16;i++)
{
    tree->Draw("evte>>h1(2000,5000,30000)", detectors[i].c_str());
    
    // 获取直方图指针
    TH1F *h1 = (TH1F*)gDirectory->Get("h1");
    
    double peak = h1->GetBinCenter(h1->GetMaximumBin()); // 获取峰值位置
    int binWidth = 100; // 设置左右对称的bin宽度
    
    
    // 定义高斯函数并设置初始参数
    TF1 *gausFit = new TF1("gausFit", "gaus", peak - binWidth, peak + binWidth);
    // gausFit->SetParameters(h1->GetMaximum(), h1->GetMean(), 400); // 设置初始参数
    
    // 使用高斯函数进行拟合
    h1->Fit(gausFit, "R"); // "R"选项用于限制在指定范围内进行拟合
    
    // 获取拟合后的参数
    gausPeak[i] = gausFit->GetParameter(1); // 获取高斯拟合的均值，即峰值位置
    gausWidth[i] = gausFit->GetParameter(2); // 获取高斯拟合的宽度
    
    // 输出峰值位置和宽度
    std::cout << "Fitted peak position: " << gausPeak[i] << std::endl;
    std::cout << "Fitted peak width: " << gausWidth[i] << std::endl;
}

// 打开文件，以追加的方式
    std::ofstream outFile("157_peaks.txt", std::ios::app);
    if (!outFile) {
        std::cerr << "无法打开文件。" << std::endl;
        return 1;
    }

    // 向文件追加内容
    outFile << "runNumber: " << fileNumber << '\t' << detectors[0].c_str() << '\t' << "peakPostions: " << gausPeak[0] <<'\t' << "peakWidth: " << gausWidth[0] << '\t'
                                                   << detectors[1].c_str() << '\t' << "peakPostions: " << gausPeak[1] <<'\t' << "peakWidth: " << gausWidth[1] << '\t'
                                                   << detectors[2].c_str() << '\t' << "peakPostions: " << gausPeak[2] <<'\t' << "peakWidth: " << gausWidth[2] << '\t'
                                                   << detectors[3].c_str() << '\t' << "peakPostions: " << gausPeak[3] <<'\t' << "peakWidth: " << gausWidth[3] << '\t'
                                                   << detectors[4].c_str() << '\t' << "peakPostions: " << gausPeak[4] <<'\t' << "peakWidth: " << gausWidth[4] << '\t'
                                                   << detectors[5].c_str() << '\t' << "peakPostions: " << gausPeak[5] <<'\t' << "peakWidth: " << gausWidth[5] << '\t'
                                                   << detectors[6].c_str() << '\t' << "peakPostions: " << gausPeak[6] <<'\t' << "peakWidth: " << gausWidth[6] << '\t'
                                                   << detectors[7].c_str() << '\t' << "peakPostions: " << gausPeak[7] <<'\t' << "peakWidth: " << gausWidth[7] << '\t'
                                                   << detectors[8].c_str() << '\t' << "peakPostions: " << gausPeak[8] <<'\t' << "peakWidth: " << gausWidth[8] << '\t'
                                                   << detectors[9].c_str() << '\t' << "peakPostions: " << gausPeak[9] <<'\t' << "peakWidth: " << gausWidth[9] << '\t'
                                                   << detectors[10].c_str() << '\t' << "peakPostions: " << gausPeak[10] <<'\t' << "peakWidth: " << gausWidth[10] << '\t'
                                                   << detectors[11].c_str() << '\t' << "peakPostions: " << gausPeak[11] <<'\t' << "peakWidth: " << gausWidth[11] << '\t'
                                                   << detectors[12].c_str() << '\t' << "peakPostions: " << gausPeak[12] <<'\t' << "peakWidth: " << gausWidth[12] << '\t'
                                                   << detectors[13].c_str() << '\t' << "peakPostions: " << gausPeak[13] <<'\t' << "peakWidth: " << gausWidth[13] << '\t'
                                                   << detectors[14].c_str() << '\t' << "peakPostions: " << gausPeak[14] <<'\t' << "peakWidth: " << gausWidth[14] << '\t'
                                                   << detectors[15].c_str() << '\t' << "peakPostions: " << gausPeak[15] <<'\t' << "peakWidth: " << gausWidth[15] << '\t'

                              << std::endl;

    // 关闭文件
    outFile.close();

}

