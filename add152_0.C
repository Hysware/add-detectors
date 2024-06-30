void add152_0(int fileNumber) {
    // 打开ROOT文件
    //TFile *file = TFile::Open("data_C1_0252_wave.root");

    std::string filename = "data_C1_0" + std::to_string(fileNumber) + "_wave.root";

    // 打开ROOT文件
    TFile *file = TFile::Open(filename.c_str());
    
    if (!file || file->IsZombie()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    // 获取树
    TTree *tree = (TTree*)file->Get("tree");  // 假设树的名字是 "tree"
    if (!tree) {
        std::cerr << "Error getting tree" << std::endl;
        file->Close();
        return;
    }

    // 创建一个新的直方图
    TH1F *hist = new TH1F("hist", "Combined Histogram", 800, 0, 100);

    // 绘制并累积数据到直方图
    /*tree->Draw("0.0031*evte-1.7055>>+hist", "sid==6&&ch==0");
    tree->Draw("0.0032*evte-1.2438>>+hist", "sid==6&&ch==3");
    tree->Draw("0.0031*evte-1.477>>+hist", "sid==6&&ch==6");
    tree->Draw("0.0032*evte-1.2655>>+hist", "sid==6&&ch==9");
    tree->Draw("0.003*evte-1.8682>>+hist", "sid==7&&ch==3");
    tree->Draw("0.0029*evte-1.2567>>+hist", "sid==7&&ch==6");
    tree->Draw("0.003*evte-1.2627>>+hist", "sid==7&&ch==9");
*/
/* 
   // 16O
    tree->Draw("0.00314*evte-1.70546>>+hist", "sid==6&&ch==0");
    tree->Draw("0.00321*evte-1.24382>>+hist", "sid==6&&ch==3");
    tree->Draw("0.00311*evte-1.47701>>+hist", "sid==6&&ch==6");
    tree->Draw("0.00316*evte-1.26559>>+hist", "sid==6&&ch==9");
    tree->Draw("0.00304*evte-0.86823>>+hist", "sid==7&&ch==3");
    tree->Draw("0.0029*evte-1.25666>>+hist", "sid==7&&ch==6");
    tree->Draw("0.00304*evte-1.26272>>+hist", "sid==7&&ch==9");

    
    // lab
    tree->Draw("0.00319*evte-0.89871>>+hist", "sid==6&&ch==0");
    tree->Draw("0.00327*evte-0.42598>>+hist", "sid==6&&ch==3");
    tree->Draw("0.00316*evte-0.66324>>+hist", "sid==6&&ch==6");
    tree->Draw("0.00321*evte-0.05084>>+hist", "sid==6&&ch==9");
    tree->Draw("0.0031*evte-0.04371>>+hist", "sid==7&&ch==3");
    tree->Draw("0.00295*evte-0.43912>>+hist", "sid==7&&ch==6");
    tree->Draw("0.00309*evte-0.44571>>+hist", "sid==7&&ch==9");
  
*/

    // int_lab
/*    tree->Draw("0.00321*evte-1.41912>>+hist", "sid==6&&ch==0");
    tree->Draw("0.00328*evte-0.86461>>+hist", "sid==6&&ch==3");
    tree->Draw("0.00317*evte-1.10279>>+hist", "sid==6&&ch==6");
    tree->Draw("0.00323*evte-0.88178>>+hist", "sid==6&&ch==9");
    tree->Draw("0.00311*evte-0.048408>>+hist", "sid==7&&ch==3");
    tree->Draw("0.00297*evte-0.87819>>+hist", "sid==7&&ch==6");
    tree->Draw("0.0031*evte-0.87829>>+hist", "sid==7&&ch==9");
*/
  tree->Draw("0.00518*evte+0.40142>>+hist", "sid==2&&ch==2");
    tree->Draw("0.00449*evte+0.49731>>+hist", "sid==2&&ch==5");
    tree->Draw("0.00511*evte+0.4965>>+hist", "sid==2&&ch==10");
    tree->Draw("0.0046*evte+0.25086>>+hist", "sid==2&&ch==15");
    tree->Draw("0.00454*evte+0.58463>>+hist", "sid==3&&ch==4");
    tree->Draw("0.00349*evte+0.55041>>+hist", "sid==3&&ch==9");
    tree->Draw("0.00447*evte+0.35469>>+hist", "sid==3&&ch==12");
    tree->Draw("0.00165*evte+0.60242>>+hist", "sid==3&&ch==15");
    tree->Draw("0.00573*evte+0.47418>>+hist", "sid==4&&ch==4");
    tree->Draw("0.00542*evte+0.28474>>+hist", "sid==4&&ch==7");
    tree->Draw("0.00577*evte+0.49287>>+hist", "sid==4&&ch==10");
    tree->Draw("0.00532*evte+0.33791>>+hist", "sid==4&&ch==15");
    tree->Draw("0.00281*evte+0.44081>>+hist", "sid==5&&ch==4");
    tree->Draw("0.0026*evte+0.48192>>+hist", "sid==5&&ch==9");
    tree->Draw("0.00273*evte+0.51487>>+hist", "sid==5&&ch==12");
    tree->Draw("0.00127*evte+0.57749>>+hist", "sid==5&&ch==15");
    // 创建一个画布并绘制直方图
    TCanvas *c1 = new TCanvas("c1", "c1", 800, 600);
    hist->Draw();

    // 保存直方图为图像文件
    //c1->SaveAs("combined_histogram.png");

    // 关闭文件
    //file->Close();
}

