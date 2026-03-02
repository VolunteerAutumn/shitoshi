#include <iostream>
#include <vector>
using namespace std;

struct Habitat
{
    string name;
    int size;
};

class Animal
{
protected:
    string name;
    int age;
    Habitat habitat;
public:
    Animal(string n, int a, Habitat h) : name(n), age(a), habitat(h) {}
    const string& getName() const { return name; }
    int getAge() const { return age; }

    virtual bool CheckIfDead() = 0;

    virtual ~Animal() {}
};

class Fox : public Animal
{
public:
    Fox(string n, int a, Habitat h) : Animal(n, a, h) {}
    bool CheckIfDead() override
    {
        return age > 13;
    }
};

class Rabbit : public Animal
{
public:
    Rabbit(string n, int a, Habitat h) : Animal(n, a, h) {}
    bool CheckIfDead() override
    {
        return age > 9;
    }
};

class Plant
{
protected:
    string name;
    bool venomous;
public:
    Plant(string n, bool v) : name(n), venomous(v) {}
    bool isVenomous() const { return venomous; }
};

class Grass : public Plant
{
public:
    Grass(string n, bool v) : Plant(n, v) {}
};

class Life
{
private:
    vector<Fox> foxes;
    vector<Rabbit> rabbits;
    vector<Grass> grasses;

public:
    void addFox(Fox f)
    {
        if (foxes.size() <= 5)
            foxes.push_back(f);
        else
            cout << "Too many foxes! No new fox appears.\n";
    }

    void addRabbit(Rabbit r)
    {
        rabbits.push_back(r);
    }

    void addGrass(Grass g)
    {
        grasses.push_back(g);
    }

    void DisplayStatus()
    {
		cout << "========== Status ==========\n";
        cout << "Foxes: " << foxes.size() << endl;
        cout << "Rabbits: " << rabbits.size() << endl;
        cout << "Grass: " << grasses.size() << endl;
		cout << "============================\n";
	}

    void simulate()
    {
		DisplayStatus();
        cout << "\n--- Simulation Start ---\n";

        // Remove dead foxes
        foxes.erase(remove_if(foxes.begin(), foxes.end(), [](Fox& f) { return f.CheckIfDead(); }), foxes.end());

        // Remove dead rabbits
        rabbits.erase(remove_if(rabbits.begin(), rabbits.end(), [](Rabbit& r) { return r.CheckIfDead(); }), rabbits.end());

        // Grass vs Rabbits
        if (grasses.size() > rabbits.size())
        {
            cout << "Grass survives.\n";
        }
        else
        {
            cout << "Rabbits eat the grass.\n";
            grasses.clear();
        }

        // Fox vs Rabbit
        if (rabbits.size() < foxes.size() && !rabbits.empty())
        {
            cout << "Foxes eat rabbits.\n";
            rabbits.clear();
        }

        cout << "Foxes: " << foxes.size() << endl;
        cout << "Rabbits: " << rabbits.size() << endl;
        cout << "Grass: " << grasses.size() << endl;

        cout << "--- Simulation End ---\n";
    }
};

int main()
{
    Habitat forest = { "Forest", 100 };

    Life world;

    world.addFox(Fox("F1", 5, forest));
    world.addFox(Fox("F2", 14, forest)); // this one dies
    world.addRabbit(Rabbit("R1", 3, forest));
    world.addRabbit(Rabbit("R2", 10, forest)); // this one dies
	  world.addFox(Fox("F3", 2, forest)); // this one eats rabbits
    world.addGrass(Grass("Grass1", false));
    world.addGrass(Grass("Grass2", false));
    world.addGrass(Grass("Grass3", false));

    world.simulate();
}

// hardest part was making Life work ngl
