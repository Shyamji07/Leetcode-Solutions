class ParkingSystem {
public:
    
    // Parking limit for each type of car
    int bigLimit, mediumLimit, smallLimit;

    // Count of cars of each type
    int bigCount, mediumCount, smallCount;

    ParkingSystem(int big, int medium, int small) {

        // Store the parking limit for each type of car
        this->bigLimit = big;
        this->mediumLimit = medium;
        this->smallLimit = small;

        // Count of cars of each type
        this->bigCount = 0;
        this->mediumCount = 0;
        this->smallCount = 0;
    }

    bool addCar(int carType) {

        // Depending on carType, decide
        if (carType == 1) {
            if (this->bigCount < this->bigLimit) {
                this->bigCount++;
                return true;
            }
            else {
                return false;
            }
        }
        else if (carType == 2) {
            if (this->mediumCount < this->mediumLimit) {
                this->mediumCount++;
                return true;
            }
            else {
                return false;
            }
        }
        else if (carType == 3) {
            if (this->smallCount < this->smallLimit) {
                this->smallCount++;
                return true;
            }
            else {
                return false;
            }
        }

        // Return False if carType is invalid. 
        // Although, this will never happen because of constraints.
        // But we are doing it for completeness.
        return false;
    }
};