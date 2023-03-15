# MSD.cpp小结
***感谢ChatGPT对我C++学习的巨大帮助***
## 输入部分
从控制台和文件的混合输入，使得可执行文件的使用体验直线上升，不用开着Ovito在看看总共有多少珠子了（因为.dump文件中都包含了这些信息）  

    cout << "Please enter dump file name:" << endl;
    string name;
    cin >> name;
    string inputSource = "file"; // start by reading from file
    ifstream inputFile(name);

    if (!inputFile.is_open()) {
        cerr << "Failed to open file for reading." << endl;
        return 1;
    }

这一段简单的代码就实现了打开一个输入到 *“name”* 的文件  
之后文件的输入就从 ***inputFile*** 开始，而从控制台输入依旧是 ***cin***  ，例如  

        int a,b;
        sting s;
        inputFile >> a;         //从文件中输入一个整型数a
        cin >> b;               //从控制台输入一个整型数b
        getline(inputFile,s);   //从控制台输入一行字符串s

当然最后关闭文件  

    inputFile.close(); // close the input file when finished

完