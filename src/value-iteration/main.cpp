#include <iostream>
#include <iomanip>

#include <Eigen/Dense>

using std::cout;
using std::endl;

typedef enum {
     left = 0, 
     up, 
     right, 
     down 
} action_t;

void printMatrix(Eigen::MatrixXd m)
{
     for (int r = 0; r < m.rows(); r++) {
          for (int c = 0; c < m.cols(); c++) {
               cout << m(r,c) << "\t";
          }
          cout << endl;
     }
}

int main(int argc, char * argv[])
{
     cout << "Value Iteration Program." << endl;

     Eigen::MatrixXd states(3,4);
     states << 1, 2, 3, 4,
          5, 6, 7, 8,
          9, 10, 11, 12;

     Eigen::MatrixXd reward(3,4);
     reward << 0, 0, 0, -1,
          0, 10, 0, -1,
          0, 0, 0, -1;

     Eigen::MatrixXd actions(4,1);
     actions << left, up, right, down;

     // Rows: Desired direction
     // Cols: Actual direction
     Eigen::MatrixXd P(4,4);
     P << 0.7, 0.1, 0.1, 0.1,
          0.1, 0.7, 0.1, 0.1,
          0.1, 0.1, 0.7, 0.1,
          0.1, 0.1, 0.1, 0.7;

     Eigen::MatrixXd V(3,4);
     V << 0, 0, 0, 0,
          0, 0, 0, 0,
          0, 0, 0, 0;
          
     cout << "===============================" << endl;
     cout << "States" << endl;
     printMatrix(states);

     cout << "===============================" << endl;
     cout << "Reward" << endl;
     printMatrix(reward);

     cout << "===============================" << endl;
     cout << "Actions" << endl;
     printMatrix(actions);

     cout << "===============================" << endl;
     cout << "P" << endl;
     printMatrix(P);

     cout << "===============================" << endl;
     cout << "V" << "_0" << endl;
     printMatrix(V);
     
     


     return 0;
}
