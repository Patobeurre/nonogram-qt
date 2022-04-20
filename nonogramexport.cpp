#include "nonogramexport.h"


/**
 * Export a nonogram puzzle into a CSV file.
 *
 * A nonogram puzzle is stored in a CSV file as one line following that shape:
 *
 * [name] , [width] , [height] , [ [value_of_line_1] , [value_of_line_2] , ...]
 *
 *  - The first three terms are the puzzle's name and dimensions.
 *  - The next values are calculated for each lines as follow:
 *      1.  The line is represented as a binary code (0 for an empty square,
 *          1 for a filled square).
 *      2.  This binary code is then converted to a number in base 10,
 *          which is the value of the line.
 *
 * @param name is the name of the new file.
 * @param ngram is the nonogram puzzle.
 * @return 0 if no errors, an 'errors' value otherwise.
 */
int NonogramExport::exportCSV(QString name, Nonogram *ngram)
{
    QDir dir;
    dir.cd(QDir::currentPath());
    if (!dir.exists(FOLDER)) {
        dir.mkdir(FOLDER);
    }
    dir.cd(FOLDER);

    QString path = dir.path();

    uint64_t w = ngram->getWidth();
    uint64_t h = ngram->getHeight();
    uint64_t *field = ngram->getField();

    QString filePath = path + "/" + name.simplified().toLower() + ".csv";
    if (QFile::exists(filePath)) {
        return ERR_FILE_EXISTS;
    }

    QFile file(filePath);
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);

        stream << name << ',';

        std::stringstream ss;
        ss << w;
        stream << QString::fromStdString(ss.str()) << ',';
        ss.str("");

        ss << h;
        stream << QString::fromStdString(ss.str()) << ',';
        ss.str("");

        for (uint64_t i = 0; i < h; ++i) {
            ss << field[i];
            stream << QString::fromStdString(ss.str());
            ss.str("");
            if (i != h - 1) {
                stream << ',';
            }
        }
        stream << "\n";

        file.close();
    }
    else {
        return ERR_WRITE_FILE;
    }

    return 0;
}


/**
 * Import a nonogram puzzle from a CSV file by the given path.
 *
 * See the 'exportCSV()' function's summary above for more details
 * about how nonograms are stored.
 *
 * @param path is the file path
 * @return the 'Nonogram' object
 */
Nonogram* NonogramExport::importCSV(QString path)
{
    uint64_t w;
    uint64_t h;
    uint64_t *field;

    QFile file(path);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString line = stream.readLine();
        file.close();

        QStringList dataStr = line.split(',');
        vector<uint64_t> data;

        bool ok;
        for (QString s : dataStr) {
            ok = false;
            uint64_t val;
            std::stringstream ss(s.toStdString());
            ss >> val;
            data.push_back(val);
        }

        w = data.at(1);
        h = data.at(2);
        field = new uint64_t[h];
        for (int i = 3; i < data.size(); ++i) {
            field[i-3] = data.at(i);
        }

        return new Nonogram(w, h, field);
    }
}
