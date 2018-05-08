# RandomTextGenerator
A ngram-based random sentences generator implemented in c++ that learns with wikipedia xml dump files.

Requirements:
  <br> - Create a folder named libs on the repo folder;
  <br> - Download boost 1_67 on https://www.boost.org/users/history/version_1_67_0.html;
  <br> - Place extracted boost in the libs folder

Installing Boost:
  <br> - once you've placed boost folder inside libs/, go to it and install all the necessary modules by using:
  <br> $./bootstrap.sh --prefix=install_dir --with-libraries=mpi --with-libraries=serialization
  <br> in case you already installed mpi in your machine, it is recommended to add the following line into the generated project-config.jam file:
  <br> using-mpi ;
  <br> - Compile selected libraries using:
  <br> $./b2 install --prefix=install_dir --with-mpi --with-serialization

How to use it:
  <br> - Clone this respository;
  <br> - Compile all necessary files using make from the available makefile;
  <br> - Run the executable with a wiki .xml of your preference, by tiping its path as an argv parameter. You can use some examples provided with this repo, such as src/wikidump.0.xml
