#include <iostream>
#include <vector>
using namespace std;

class TimeSeriesGenerator{
    int seed;
    TimeSeriesGenerator(){};
    TimeSeriesGenerator(int seed){};

    virtual vector<double> generateTimeSeries(int maxsize) const =0;
    static void printTimeSeries(const std::vector<double>& series) {
       for (const double& value : series) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }



};

class TimeSeriesGenerator {
protected:
    int seed; // Attribut pour la graine aléatoire

public:
    // Constructeur par défaut
    TimeSeriesGenerator() : seed(0) {}

    // Constructeur paramétré
    TimeSeriesGenerator(int s) : seed(s) {}

    // Fonction virtuelle pure pour générer une série temporelle
    virtual std::vector<double> generateTimeSeries(int size) const = 0;

    // Fonction statique pour afficher une série temporelle
    static void printTimeSeries(const std::vector<double>& series) {
        for (const double& value : series) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // Virtual destructor
    virtual ~TimeSeriesGenerator() {}
};
