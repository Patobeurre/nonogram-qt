#ifndef NONOGRAMEXPORT_H
#define NONOGRAMEXPORT_H

#include "nonogram.h"

#include <QDebug>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <sstream>

#define FOLDER "custom_puzzles"


/**
 * Supported error types.
 *
 * These values are used in functions that need to manipulate files.
 * They can be seen as exception types.
 *
 * @author Patobeur
 */
enum errors {
    /// Used if file already exists
    ERR_FILE_EXISTS = -1,
    ERR_WRITE_FILE = -2,
};


/**
 * Provides static functions to import and export nonograms.
 */
class NonogramExport
{

public:
    /// Export a nonogram into file.
    static int exportCSV(QString name, Nonogram *ngram);
    /// Import a nonogram from file.
    static Nonogram* importCSV(QString path);

};

#endif // NONOGRAMEXPORT_H
