
#include "crow_all.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>

struct Movie {
    std::string title, genre, director, poster;
    double rating;
    int year;
};

std::vector<Movie> loadMovies() {
    std::vector<Movie> movies;
    std::ifstream file("movies.csv");
    std::string line;
    getline(file, line);
    while(getline(file,line)){
        std::stringstream ss(line);
        std::string t,g,r,y,d,p;
        getline(ss,t,','); getline(ss,g,','); getline(ss,r,',');
        getline(ss,y,','); getline(ss,d,','); getline(ss,p,',');
        movies.push_back({t,g,d,p,stod(r),stoi(y)});
    }
    return movies;
}

// simple auth
std::map<std::string,std::string> users;

int main(){
    crow::SimpleApp app;
    auto movies = loadMovies();

    CROW_ROUTE(app,"/signup").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        users[x["user"].s()] = x["pass"].s();
        return "User created";
    });

    CROW_ROUTE(app,"/login").methods("POST"_method)
    ([](const crow::request& req){
        auto x = crow::json::load(req.body);
        if(users[x["user"].s()] == x["pass"].s())
            return crow::response(200,"Login success");
        return crow::response(403,"Invalid");
    });

    CROW_ROUTE(app,"/movies")
    ([&movies](){
        crow::json::wvalue res;
        int i=0;
        for(auto&m:movies){
            res[i]["title"]=m.title;
            res[i]["genre"]=m.genre;
            res[i]["rating"]=m.rating;
            res[i]["poster"]=m.poster;
            i++;
        }
        return res;
    });

    app.port(18080).run();
}
