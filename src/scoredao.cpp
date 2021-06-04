#include "scoredao.hpp"

ScoreDAO::ScoreDAO()
{
    myDatabase = QSqlDatabase::addDatabase(DATABASE_TYPE);
    myDatabase.setDatabaseName(DATABASE_NAME);
    if(myDatabase.open())
    {
        QSqlQuery queryCreation{myDatabase};
        queryCreation.exec("CREATE TABLE IF NOT EXISTS Stats ( Id INTEGER PRIMARY KEY AUTOINCREMENT,score INTEGER,moment VARCHAR);");
    }
}

ScoreDAO::~ScoreDAO()
{
    myDatabase.close();
}

void ScoreDAO::insertScore(int scoreToAdd)
{
    QSqlQuery insertQuery{myDatabase};
    insertQuery.prepare("INSERT INTO Stats(score,moment)"
                        "VALUES (:score,:moment)");
    insertQuery.bindValue(":score",scoreToAdd);
    insertQuery.bindValue(":moment",QDateTime::currentDateTime().toString());
    insertQuery.exec();
}

QList<int> ScoreDAO::getAll()
{
    QList<int> scoresLoaded{};
    auto queryAll = myDatabase.exec("SELECT score FROM Stats");
    while(queryAll.next())
    {
        scoresLoaded.push_back(queryAll.value(0).toInt());
    }
    return scoresLoaded;
}

int ScoreDAO::getMaxScore()
{
    auto queryBest = myDatabase.exec("SELECT MAX(score) FROM Stats");
    // We want to be on a valid record
    queryBest.first();
    auto const best{queryBest.value(0).toInt()};
    return best;
}


