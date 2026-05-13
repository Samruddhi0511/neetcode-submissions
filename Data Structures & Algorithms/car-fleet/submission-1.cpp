class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // first v make a vector pair of pos and time

        vector<pair<int, double>> cars;

        for(int i=0; i<position.size(); i++){
            double time=(double)(target-position[i])/ speed[i];
            cars.push_back({position[i], time});
        }

        // sort by position nearest to the target cus if farther then can catch up if speed more

        sort(cars.begin(), cars.end(), [](const auto& a, const auto& b){
            return a.first>b.first;
        });

        // now v form a stack in which we will add a new fleet if the time needed is more than the existing one;
        //this will work becus since v have sorted the ones already existing in stack asre basically v near tho the target
        //hence they can b caught opn only if the tim eo fthe farther ones is less

        stack <double> car_fleets;
        for(int i=0; i<cars.size(); i++){ // empty only for th efirst fleet
            if(car_fleets.empty() || cars[i].second > car_fleets.top()){
                car_fleets.push(cars[i].second);
            }
        }

        return car_fleets.size();
    }
};
