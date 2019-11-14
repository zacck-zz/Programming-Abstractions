#ifndef SHOWFILECONTENTS_H
#define SHOWFILECONTENTS_H

std::string promptForFile(std::ifstream & infile, std::string prompt);
int stringToInt(std::string str);
int getInt(std::string str);
void copyStream(std::istream & is, std::ostream & os);

#endif // SHOWFILECONTENTS_H
