#ifndef QFLAPPYBIRD_SCOREDAO_HPP
#define QFLAPPYBIRD_SCOREDAO_HPP

#include <QList>
#include <QVariant>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlResult>
#include <QDateTime>
#include <QSqlDriver>
#include <QSqlDatabase>

class ScoreDAO
{
public:
    ScoreDAO();
    ~ScoreDAO();
    void insertScore(int scoreToAdd);
    QList<int> getAll();
    int getMaxScore();

private:
    const QString DATABASE_TYPE{"QSQLITE"};
    const QString DATABASE_NAME{"QFlappyBird_Scores.db"};
    QSqlDatabase myDatabase;
};


#endif //QFLAPPYBIRD_SCOREDAO_HPP
