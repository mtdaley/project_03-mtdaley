/*
 * Miles Daley
 * CS124
 * Section A
 */

#ifndef PROJECT_01_PROSPECTS_H
#define PROJECT_01_PROSPECTS_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

class Prospects {

private:
    std::string name, team, level, playerId;
    int age, pa;
    double bbRate, kRate, avg, obp, slg, ops, iso, babip, wOba, wRCPlus;

public:
    Prospects() {

    }

    Prospects(int age,
              std::string playerId,
              int pa,
              double bbRate,
              double kRate,
              double avg,
              double obp,
              double slg,
              double ops,
              double iso,
              double babip,
              double wOba,
              double wRCPlus,
              std::string name,
              std::string team,
              std::string level) {
        this->age = age;
        this->playerId = playerId;
        this->pa = pa;
        this->bbRate = bbRate;
        this->kRate = kRate;
        this->avg = avg;
        this->obp = obp;
        this->slg = slg;
        this->ops = ops;
        this->iso = iso;
        this->babip = babip;
        this->wOba = wOba;
        this->wRCPlus = wRCPlus;
        this->name = name;
        this->team = team;
        this->level = level;

    }

    // Getters
    int getAge() const {
        return age;
    }

    std::string getPlayerID() const {
        return playerId;
    }

    int getPA() const {
        return pa;
    }

    double getBBRate() const {
        return bbRate;
    }

    double getKRate() const {
        return kRate;
    }

    double getAvg() const {
        return avg;
    }

    double getObp() const {
        return obp;
    }

    double getSlg() const {
        return slg;
    }

    double getOps() const {
        return ops;
    }

    double getIso() const {
        return iso;
    }

    double getBabip() const {
        return babip;
    }

    double getwOba() const {
        return wOba;
    }

    double getwRCPlus() const {
        return wRCPlus;
    }

    std::string getName() const {
        return name;
    }

    std::string getTeam() const {
        return team;
    }

    std::string getLevel() const {
        return level;
    }

    // Setters
    void setName(std::string name) {
        this->name = name;
    }

    void setTeam(std::string team) {
        this->team = team;
    }

    void setLevel(std::string level) {
        this->level = level;
    }

    void setAge(int age) {
        this->age = age;
    }

    void setPA(int pa) {
        this->pa = pa;
    }

    void setPlayerID(std::string playerId) {
        this->playerId = playerId;
    }

    void setBBRate(double bbRate) {
        this->bbRate = bbRate;
    }

    void setKRate(double kRate) {
        this->kRate = kRate;
    }

    void setAvg(double avg) {
        this->avg = avg;
    }

    void setObp(double obp) {
        this->obp = obp;
    }

    void setSlg(double slg) {
        this->slg = slg;
    }

    void setOps(double ops) {
        this->ops = ops;
    }

    void setIso(double iso) {
        this->iso = iso;
    }

    void setBabip(double babip) {
        this->babip = babip;
    }

    void setwOba(double wOba) {
        this->wOba = wOba;
    }

    void setwRCplus(double wRCPlus) {
        this->wRCPlus = wRCPlus;
    }
    friend std::ostream& operator << (std::ostream& outs, const Prospects& pObj) {
        outs << std::fixed
             << std::right
             << std::setprecision(4)
             << std::setw(6) << pObj.getName()
             << std::setw(5) << "Team:"
             << std::setw(2) << pObj.getTeam()
             << std::left
             << "  "
             << std::setw(5) << "Age:"
             << std::setw(5) << pObj.getAge()
             << std::setw(5) << "PA:"
             << std::setw(5) << pObj.getPA()
             << std::setw(5) << "BB%:"
             << std::setw(5) << pObj.getBBRate()
             << std::right
             << std::setw(5) << "K%:"
             << std::setw(7) << pObj.getKRate()
             << std::setw(5) << "AVG:"
             << std::setw(7) << pObj.getAvg()
             << std::setw(5) << "OBP:"
             << std::setw(7) << pObj.getObp()
             << std::setw(5) << "SLG:"
             << std::setw(7) << pObj.getSlg()
             << std::setw(5) << "OPS:"
             << std::setw(7) << pObj.getOps()
             << std::setw(5) << "ISO:"
             << std::setw(7) << pObj.getIso()
             << std::setw(7) << "BABIP:"
             << std::setw(8) << pObj.getBabip()
             << std::setw(6) << "wOBA:"
             << std::setw(8) << pObj.getwOba()
             << std::setw(6) << "wRC+:"
             << std::setw(10) << pObj.getwRCPlus()
             << std::setw(11) << "Player ID:"
             << std::setw(6) << pObj.getPlayerID();
        return outs;
    }
    friend bool operator == (const Prospects& lhs, const Prospects& rhs) {
        return lhs.getPlayerID() == rhs.getPlayerID();
    }

    friend bool operator > (const Prospects& lhs, const Prospects& rhs) {
        // Some IDs begin with "sa" followed by an int so need to remove that before comparison
        std::string chars = "sa";
        std::string lefId = lhs.getPlayerID();
        std::string riId = rhs.getPlayerID();
        for (char c: chars) {
            lefId.erase(std::remove(lefId.begin(), lefId.end(), c), lefId.end());
            riId.erase(std::remove(riId.begin(), riId.end(), c), riId.end());
        }
        int lh = stoi(lefId);
        int rh = stoi(riId);
        return lh > rh;
    }

    friend bool operator >= (const Prospects& lhs, const Prospects& rhs) {
        std::string chars = "sa";
        std::string lefId = lhs.getPlayerID();
        std::string riId = rhs.getPlayerID();
        for (char c: chars) {
            lefId.erase(std::remove(lefId.begin(), lefId.end(), c), lefId.end());
            riId.erase(std::remove(riId.begin(), riId.end(), c), riId.end());
        }
        int lh = stoi(lefId);
        int rh = stoi(riId);
        return lh >= rh;
    }

    friend bool operator < (const Prospects& lhs, const Prospects& rhs) {
        std::string chars = "sa";
        std::string lefId = lhs.getPlayerID();
        std::string riId = rhs.getPlayerID();
        for (char c: chars) {
            lefId.erase(std::remove(lefId.begin(), lefId.end(), c), lefId.end());
            riId.erase(std::remove(riId.begin(), riId.end(), c), riId.end());
        }
        int lh = stoi(lefId);
        int rh = stoi(riId);
        return lh < rh;
    }

    friend bool operator <= (const Prospects& lhs, const Prospects& rhs) {
        std::string chars = "sa";
        std::string lefId = lhs.getPlayerID();
        std::string riId = rhs.getPlayerID();
        for (char c: chars) {
            lefId.erase(std::remove(lefId.begin(), lefId.end(), c), lefId.end());
            riId.erase(std::remove(riId.begin(), riId.end(), c), riId.end());
        }
        int lh = stoi(lefId);
        int rh = stoi(riId);
        return lh <= rh;
    }

};



bool loadFromFile(std::string fn, std::vector<Prospects>& objs) {
    std::ifstream fin;
    fin.open(fn);
    if (!fin) {
        // Bad file / could not open
        return false;
    }

    // Opened file

    std::string header = "";
    getline(fin, header);

    int counter = 1;
    while (fin && fin.peek() != EOF){
        std::string playId = "INVALID";
        std::string playName = "INVALID";
        std::string playTeam = "INVALID";
        std::string playLevel = "INVALID";
        int playAge = -1;
        int playPA = -1;
        double playBBRate = -1.0;
        double playKRate = -1.0;
        double playAvg = -1.0;
        double playObp = -1.0;
        double playSlg = -1.0;
        double playOps = -1.0;
        double playIso = -1.0;
        double playBabip = -1.0;
        double playwOba = -1.0;
        double playwRCPlus = -1.0;
        char comma = ',';
        char doubleQuote = '"';

        getline(fin, playName, comma);
        getline(fin, playTeam, comma);
        if(fin.peek() == doubleQuote){
            fin >> doubleQuote;
            getline(fin, playLevel, doubleQuote);
            fin >> comma;
        } else {
            getline(fin, playLevel, comma);
        }
        fin >> playAge;
        fin >> comma;
        fin >> playPA;
        fin >> comma;
        fin >> playBBRate;
        fin >> comma;
        fin >> playKRate;
        fin >> comma;
        fin >> playAvg;
        fin >> comma;
        fin >> playObp;
        fin >> comma;
        fin >> playSlg;
        fin >> comma;
        fin >> playOps;
        fin >> comma;
        fin >> playIso;
        fin >> comma;
        fin >> playBabip;
        fin >> comma;
        fin >> playwOba;
        fin >> comma;
        fin >> playwRCPlus;
        fin >> comma;
        getline(fin, playId, '\n');
        playId.erase(playId.size() - 1);
        Prospects playerData(playAge, playId, playPA, playBBRate, playKRate,
                             playAvg, playObp, playSlg, playOps, playIso, playBabip,
                             playwOba, playwRCPlus, playName, playTeam, playLevel);
        objs.push_back(playerData);





    }
    fin.close();
    return true;


}

// split function sourced from: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void showPopulationStats(std::vector<Prospects>& objs) {
    int aBall = 0;
    int aPlus = 0;
    int aa = 0;
    int aaa = 0;
    int cpx = 0;
    int dsl = 0;
    int total;

    for (Prospects& play : objs) {
        std::string level = play.getLevel();
        if (level.find(',') != std::string::npos) {
            std::vector<std::string> multLevels = split(level, ",");
            for (std::string lvl: multLevels) {
                if (lvl == "DSL") {
                    dsl += 1;
                } else if (lvl == "CPX") {
                    cpx += 1;
                } else if (lvl == "A") {
                    aBall += 1;
                } else if (lvl == "A+") {
                    aPlus += 1;
                } else if (lvl == "AA") {
                    aa += 1;
                } else if (lvl == "AAA") {
                    aaa += 1;
                }
            }


        } else {
            if (level == "DSL") {
                dsl += 1;
            } else if (level == "CPX") {
                cpx += 1;
            } else if (level == "A") {
                aBall += 1;
            } else if (level == "A+") {
                aPlus += 1;
            } else if (level == "AA") {
                aa += 1;
            } else if (level == "AAA") {
                aaa += 1;
            }
        }
    }
    total = cpx + dsl + aBall + aPlus + aa + aaa;

    std::cout << std::endl;
    std::cout << "MiLB Population statistics" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Dominican Summer League" << std::right << std::setw(10)
              << dsl << std::endl;
    std::cout << "Complex League" << std::right << std::setw(19)
              << cpx << std::endl;
    std::cout << "A Ball" << std::right << std::setw(27)
              << aBall << std::endl;
    std::cout << "High A" << std::right << std::setw(27)
              << aPlus << std::endl;
    std::cout << "Double A" << std::right << std::setw(25)
              << aa << std::endl;
    std::cout << "Triple A" << std::right << std::setw(25)
              << aaa << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Total" << std::right << std::setw(28)
              << total << std::endl;
    std::cout << "=================================" << std::endl;

}

void averageAge(std::vector<Prospects>& objs){
    int aBall = 0;
    int aAge = 0;
    int aPlus = 0;
    int aPlusAge = 0;
    int aa = 0;
    int aaAge = 0;
    int aaa = 0;
    int aaaAge = 0;
    int cpx = 0;
    int cpxAge = 0;
    int dsl = 0;
    int dslAge = 0;
    int total;
    int totalAge;
    for (Prospects& play : objs) {
        std::string level = play.getLevel();
        if (level.find(',') != std::string::npos) {
            std::vector<std::string> multLevels = split(level, ",");
            for (std::string lvl: multLevels) {
                if (lvl == "DSL") {
                    dsl += 1.0;
                    dslAge += play.getAge();
                } else if (lvl == "CPX") {
                    cpx += 1.0;
                    cpxAge += play.getAge();
                } else if (lvl == "A") {
                    aBall += 1.0;
                    aAge += play.getAge();
                } else if (lvl == "A+") {
                    aPlus += 1.0;
                    aPlusAge += play.getAge();
                } else if (lvl == "AA") {
                    aa += 1.0;
                    aaAge += play.getAge();
                } else if (lvl == "AAA") {
                    aaa += 1.0;
                    aaaAge += play.getAge();
                }
            }


        } else {
            if (level == "DSL") {
                dsl += 1.0;
                dslAge += play.getAge();
            } else if (level == "CPX") {
                cpx += 1.0;
                cpxAge += play.getAge();
            } else if (level == "A") {
                aBall += 1.0;
                aAge += play.getAge();
            } else if (level == "A+") {
                aPlus += 1.0;
                aPlusAge += play.getAge();
            } else if (level == "AA") {
                aa += 1.0;
                aaAge += play.getAge();
            } else if (level == "AAA") {
                aaa += 1.0;
                aaaAge += play.getAge();
            }
        }
    }
    total = cpx + dsl + aBall + aPlus + aa + aaa + 0.0;
    totalAge = cpxAge + dslAge + aAge + aPlusAge + aaAge + aaaAge + 0.0;
    std::cout << std::endl;
    std::cout << "MiLB Age statistics" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Dominican Summer League" << std::right << std::setw(10) << std::setprecision(3)
              << 1.0 * dslAge / dsl << std::endl;
    std::cout << "Complex League" << std::right << std::setw(19) << std::setprecision(3)
              << 1.0 * cpxAge / cpx << std::endl;
    std::cout << "A Ball" << std::right << std::setw(27) << std::setprecision(3)
              << 1.0 * aAge / aBall << std::endl;
    std::cout << "High A" << std::right << std::setw(27) << std::setprecision(3)
              << 1.0 * aPlusAge / aPlus << std::endl;
    std::cout << "Double A" << std::right << std::setw(25) << std::setprecision(3)
              << 1.0 * aaAge / aa << std::endl;
    std::cout << "Triple A" << std::right << std::setw(25) << std::setprecision(3)
              << 1.0 * aaaAge / aaa << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "Total" << std::right << std::setw(28) << std::setprecision(3)
              << 1.0 * totalAge / total << std::endl;
    std::cout << "=================================" << std::endl;
}

void prospectsTest(){
    Prospects test = Prospects();
    test.setAge(1);
    assert (test.getAge() == 1);
    test.setAvg(1.0);
    assert (test.getAvg() == 1.0);
    test.setBBRate(1.0);
    assert (test.getBBRate() == 1.0);
    test.setBabip(1.0);
    assert (test.getBabip() == 1.0);
    test.setIso(1.0);
    assert (test.getIso() == 1.0);
    test.setKRate(1.0);
    assert(test.getKRate() == 1.0);
    test.setName("Bill");
    assert(test.getName() == "Bill");
    test.setPlayerID("id");
    assert(test.getPlayerID() == "id");
    test.setLevel("A");
    assert(test.getLevel() == "A");
    test.setObp(1.0);
    assert(test.getObp() == 1.0);
    test.setOps(1.0);
    assert(test.getOps() == 1.0);
    test.setPA(1);
    assert(test.getPA() == 1);
    test.setSlg(1.0);
    assert(test.getSlg() == 1.0);
    test.setwOba(1.0);
    assert(test.getwOba() == 1.0);
    test.setwRCplus(1.0);
    assert(test.getwRCPlus() == 1.0);
    test.setTeam("T");
    assert(test.getTeam() == "T");
}




#endif //PROJECT_01_PROSPECTS_H
