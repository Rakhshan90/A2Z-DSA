/*
Problem statment: We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
Input: asteroids = [5,10,-5]
Output: [5,10]
Input: asteroids = [10, 2, 7, -5, -9]
Output: [10]
Input: asteroids = [-4, 3, 2, -2, 1]
Output: [-4, 3, 1]
*/

/*
Approach: Optimized

Condition for collision: By observation, we can say if current asteroid is moving to the right and next asteroid is moving to the left then only they will collide.

1. For each asteroid val, it checks if the stack is empty. If it is, we will simply pushes the asteroid onto the stack.
2. Otherwise, we checks if the top asteroid on the stack has a positive sign and the current asteroid has negative sign. If it does, it means a collision occurs.
3. Then, we checks if the absolute value of the current asteroid is greater than the absolute value of the top asteroid. If it is, it means the current asteroid survives the collision, and the top asteroid is destroyed. We will pop and push the current asteroid in the stack.
4. If the absolute value of the current asteroid is less than the absolute value of the top asteroid, it means the current asteroid is destroyed, and we skips processing the rest of the asteroids in the stack.
If the absolute values of the current asteroid and the top asteroid are equal, it means both asteroids are destroyed.
5. If both asteroids are destroyed, we will pops the top asteroid from the stack and don't consider the current asteroid.
6. Finally, we will check if either stack is empty, collision not occured, and current asteroid survives after collision then we pushes the current asteroid onto the stack.
7. After processing all asteroids, the stack contains the remaining asteroids after all collisions.
8. then creates an empty vector ans of size equal to the size of the stack.
9. popping each asteroid from the stack and adding it to the ans vector from back of the ans vector.
10. Finally, it returns the ans vector, which contains the remaining asteroids in the correct order.

TC: O(n), SC: O(n)
*/

/*
vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int val:asteroids){
            bool flag = true;
            while(!st.empty() && (st.top() > 0 && val < 0)){
                if(abs(st.top()) < abs(val)){
                    //current asteroid survived
                    st.pop();
                    continue;
                }
                else if(abs(st.top()) > abs(val)){
                    //asteroid on top of stack will survived
                    flag = false;
                    break;
                }
                //when values are equal, both asteroid will destroyed
                else{
                    st.pop();
                    flag = false;
                    break;
                }
            }
            if(flag) st.push(val);
        }
        vector<int>ans(st.size());
        for(int i=ans.size()-1; i>=0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
*/