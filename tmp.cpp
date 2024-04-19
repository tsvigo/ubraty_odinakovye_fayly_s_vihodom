   std::ifstream is2("/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/spisok.txt");  
     std::istream_iterator<std::string> start2(is2), end2;  
     std::vector<std::string> list_of_fonts(start2, end2);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   QString stroka1=
   "magick compare -metric MAE \"/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/";
//list_of_fonts[0]; 
QString stroka2="\" \"/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/";
//list_of_fonts[1] ;
QString stroka3="\" null: 2>&1"; 
bool file_stiort=false;
QProcess process;
QString  stroka_vsia;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// TODO: прочитать x и y из файла
QFile inputFile("/home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_vihodom/x.txt");
if (inputFile.open(QIODevice::ReadOnly))
{
   QTextStream in(&inputFile);
  // while (!in.atEnd())
   {
      QString line = in.readLine();
  x=  line.toInt();
   }
   inputFile.close();
}


QFile inputFile2("/home/viktor/my_projects_qt_2/ubraty_odinakovye_fayly_s_vihodom/y.txt");
if (inputFile2.open(QIODevice::ReadOnly))
{
   QTextStream in(&inputFile2);
  // while (!in.atEnd())
   {
      QString line2 = in.readLine();
 y=  line2.toInt();
   }
   inputFile.close();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// .
/// цикл не даёт
    for ( ;y<2461 ; y++)  
     for ( x=y+1;x<2462 ; x++)  
        {
               stroka_vsia=stroka1+list_of_fonts[y].c_str()+stroka2+list_of_fonts[x].c_str()  +stroka3;
             
             
             process.start(stroka_vsia.toStdString().c_str());
    process.waitForFinished(-1); // will wait forever until finished
             QString stderr = process.readAllStandardError();
        

 std::cout << stderr.toStdString().c_str()  << std::endl; 

 if (stderr=="0 (0)")   
             {
// std::cout << "!!!!!!"<< std::endl ; // TODO: стереть файл второй
QString name_of_file="/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/"
+QString::fromStdString(list_of_fonts[x]); // QString::fromStdString(str);
 file_stiort=QFile::remove(name_of_file);
            if (file_stiort ==true)
            std::cout << "файл "+list_of_fonts[x]+" стёрт"<< std::endl ; // TODO: стереть файл второй;
            else 
            std::cout << "файл "+list_of_fonts[x]+" не стёрт"<< std::endl ;
            
             }
          }
