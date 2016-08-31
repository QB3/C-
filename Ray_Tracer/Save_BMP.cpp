
void Create_Save_BMP()  {
    int x=0;
    int iWidth = 256;
    int iHeight = 256;
    HANDLE file;
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER fileInfo;
    RGBTRIPLE image;
    DWORD write = 0;
 
    file = CreateFile("examplea.bmp",GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
    fileHeader.bfType = 19778;
    fileHeader.bfSize = sizeof(fileHeader.bfOffBits) + sizeof(RGBTRIPLE);
    fileHeader.bfReserved1 = 0;
    fileHeader.bfReserved2 = 0;
    fileHeader.bfOffBits = sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER);
 
    fileInfo.biSize = sizeof(BITMAPINFOHEADER);
    fileInfo.biWidth = iWidth;
    fileInfo.biHeight = iHeight;
    fileInfo.biPlanes = 1;
    fileInfo.biBitCount = 24;
    fileInfo.biCompression = BI_RGB;
    fileInfo.biSizeImage = 0;
    fileInfo.biXPelsPerMeter = 0;
    fileInfo.biYPelsPerMeter = 0;
    fileInfo.biClrImportant = 0;
    fileInfo.biClrUsed = 0;
 
    WriteFile(file,&fileHeader,sizeof(fileHeader),&write,NULL);
    WriteFile(file,&fileInfo,sizeof(fileInfo),&write,NULL);
 
    for (int i = 0; i < (iWidth*iHeight); i++)
    {
        if (i <= iWidth*iHeight/2-1)
           { x=254;}
        else {x=5;}
        image.rgbtBlue = x-1;
        image.rgbtGreen = x-1;
        image.rgbtRed = x-1;
        WriteFile(file, &image, sizeof(RGBTRIPLE), &write, NULL);
    }
    CloseHandle(file);
}
