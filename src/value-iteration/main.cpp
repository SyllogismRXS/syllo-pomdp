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
               cout << std::setprecision(3) << m(r,c) << "\t";
          }
          cout << endl;
     }
}

int main(int argc, char * argv[])
{
     cout << "Value Iteration Program." << endl;

     Eigen::MatrixXd S(5,5);
     S << 
          1, 2, 3, 4, 5,
          6, 7, 8, 9, 10,
          11, 12, 13, 14, 15,
          16, 17, 18, 19, 20,
          21, 22, 23, 24, 25;

     Eigen::MatrixXd R(5,5);
     R << 
          0, 0, 0,  0,  0,
          0, 0, 0,  0, -1,
          0, 0, 10, 0, -1,
          0, 0, 0,  0, -1,
          0, 0, 0,  0,  0;

     Eigen::MatrixXd actions(4,1);
     actions << left, up, right, down;

     // Rows: Desired direction
     // Cols: Actual direction
     Eigen::MatrixXd P(4,4);
     P << 0.7, 0.1, 0.1, 0.1,
          0.1, 0.7, 0.1, 0.1,
          0.1, 0.1, 0.7, 0.1,
          0.1, 0.1, 0.1, 0.7;

     Eigen::MatrixXd V_prev(5,5);
     Eigen::MatrixXd V(5,5);
     V << 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0,
          0, 0, 0, 0, 0;
     V_prev = V;
          
     cout << "===============================" << endl;
     cout << "States" << endl;
     printMatrix(S);

     cout << "===============================" << endl;
     cout << "Reward" << endl;
     printMatrix(R);

     cout << "===============================" << endl;
     cout << "Actions" << endl;
     printMatrix(actions);

     cout << "===============================" << endl;
     cout << "P" << endl;
     printMatrix(P);

     cout << "===============================" << endl;
     cout << "V" << "_0" << endl;
     printMatrix(V);

     double discount = 0.9;
     cout << "===============================" << endl;
     cout << "Discount: " << discount << endl; 
     cout << "===============================" << endl;
     cout << "Starting..." << endl;
     cout << "===============================" << endl;

     for (int k = 1; k < 4; k++) {
          // For each state... (using 3x3 state matrix)
          for (int r = 1; r < S.rows()-1; r++) {
               for (int c = 1; c < S.cols()-1; c++) {               
                    double champ = -9999;

                    // For each action...
                    for(int a = 0; a < actions.rows(); a++) {                    
                         double value = 0;
                         // Over possible resulting states...
                         for(int s_tick = 0; s_tick < P.cols(); s_tick++) {
                              
                              double R_cur = 0;
                              if (s_tick == right && R(r,c+1) == -1) {
                                   R_cur = -1;
                              } else {
                                   R_cur = R(r,c);
                              }

                              double V_future = 0;
                              switch (s_tick) {
                              case left:
                                   V_future = V_prev(r,c-1);
                                   break;
                              case up:
                                   V_future = V_prev(r-1,c);
                                   break;
                              case right:
                                   V_future = V_prev(r,c+1);
                                   break;
                              case down:
                                   V_future = V_prev(r+1,c);
                                   break;
                              default:
                                   cout << "Invalid" << endl;
                                   break;
                              }

                              value += P(a,s_tick)*(R_cur + discount*V_future);
                              
                              //if (r == 2 && c == 2) {
                              //     cout << "------------------------" << endl;
                              //     cout << "Row: " << r << "\t" << "Col: " << c << endl;
                              //     cout << "Action: " << a << endl;
                              //     cout << "P(a,s_tick): " << P(a,s_tick) << endl;
                              //     cout << "R(r,c): " << R_cur << endl;
                              //     cout << "value: " << value << endl;
                              //}
                         }
                    
                         if (value > champ) {
                              champ = value;
                         }                    

                    } // end action loop               
                    V(r,c) = champ;
               } // end column loop
          } // end state loop
          
          cout << "===============================" << endl;
          cout << "V" << "_" << k << endl;
          printMatrix(V);
          V_prev = V;

     } // end k = k + 1
     
     return 0;
}
