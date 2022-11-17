import numpy as np
np.set_printoptions(precision= 'maxprec', formatter={'float': lambda x: "{0:0.2f}".format(x)})

class HiddenMarkovModel():

    OBSTACLE_TP = 0.85
    OBSTACLE_FP = 0.05

    OPEN_FP = 0.15
    OPEN_TP = 0.95

    def __init__(self):
        self.matrix = Matrix(6, 7)
        self.northTransitionMatrix = self.matrix.createTransitionMatrix("NORTH")
        self.westTransitionMatrix = self.matrix.createTransitionMatrix("WEST")
        self.probabilityMatrix = self.matrix.createInitialMatrix()

    def sensorUpdate(self, perception):
        #Assign the tuple to these values
        w, n, e, s = perception
        tempMatrix = self.probabilityMatrix
        self.matrix.representAsPerecentage(self.probabilityMatrix,False)
       
        #For loop iterating through each state in matrix
        for x in range(0, 6):

            for y in range(0, 7):
                #Sets the probability of each state in each direction
                westProb = self.assignSensedProb((x, y - 1), w)
                northProb = self.assignSensedProb((x - 1, y), n)
                eastProb = self.assignSensedProb((x, y + 1), e)
                southProb = self.assignSensedProb((x + 1, y), s)

                initial = self.probabilityMatrix[x][y]
                probability = (westProb * northProb * eastProb * southProb) * initial
                tempMatrix[x][y] = probability


        #Takes our valuesa and divides them by the normalizer to give us propper prob
        tempMatrix /= np.sum(tempMatrix)
        #Convert it to a percent
        self.matrix.representAsPerecentage(tempMatrix, True)
        

        self.probabilityMatrix = tempMatrix

    def motionUpdate(self, heading):
        tempMatrix = self.probabilityMatrix

        #Takes our probaility matrix and converts it back to decimals
        self.matrix.representAsPerecentage(tempMatrix, False)

        tempMatrix = tempMatrix.flatten()
        #Prediction
        if heading == "NORTH":
            tempMatrix = tempMatrix.dot(self.northTransitionMatrix)
        elif heading == "WEST":
            tempMatrix = tempMatrix.dot(self.westTransitionMatrix)

        tempMatrix = tempMatrix.reshape(6, 7)
        self.matrix.representAsPerecentage(tempMatrix, True)
        self.probabilityMatrix = tempMatrix


    def assignSensedProb(self, state, evidence):
        #Cordinates
        x, y = state

        if self.matrix.isNotAnObstacle((x, y)) and self.matrix.isInMaze((x, y)):
            if(evidence == "1"):
                return self.OBSTACLE_FP
            else:
                return self.OPEN_TP
        else:
            # If state is an obstacle
            if(evidence == "1"):
                # Robot sees an obstacle
                return self.OBSTACLE_TP
            else:
                # Robot sees state
                return self.OPEN_FP


    def printGrid(self):
        self.matrix.printMatrix(self.probabilityMatrix)

class Matrix():

    def __init__(self, height, width):
        # Make a 6 x 7 matrix
        self.width = width
        self.height = height
        #42 - 5 obstacles
        self.numberOfStates = 37

    def assignObstacleProb(self, matrix):  
        matrix[1][5] = 0.00
        matrix[2][1] = 0.00
        matrix[2][4] = 0.00
        matrix[3][1] = 0.00
        matrix[3][4] = 0.00

    def createInitialMatrix(self):
        #Sets the initial probs given the number of states
        priorList = [[(float(1) / self.numberOfStates) * 100.00] * self.width] * self.height
        initialMatrix = np.array(priorList)

        #Set up the obstacles inside the maze
        self.assignObstacleProb(initialMatrix)

        print("Initial Probabilities")
        for row in initialMatrix:
            print(row)
            print(" ")
        print("------------------------------------------------------------------\n")

        return initialMatrix

    def createTransitionMatrix(self, heading):

        #Create an empty matrix that is 6 X 7
        transitionMatrix = np.empty(shape=(1, 42))
        #For range in rows
        for x in range(0, self.height):
            #For range in columns
            for y in range(0, self.width):
                stateMatrix = np.array([[round(0.000, 2)] * self.width] * self.height)
                #Does condition if it is an actual state
                if self.isNotAnObstacle((x, y)):
                    self.assignTransitionProb(heading, (x, y), stateMatrix)
                    stateMatrix = stateMatrix.flatten()
                    transitionMatrix = np.vstack((transitionMatrix, stateMatrix))
                else:
                    stateMatrix = stateMatrix.flatten()
                    transitionMatrix = np.vstack((transitionMatrix, stateMatrix))

        # Delete first row (irrelevant)
        transitionMatrix = np.delete(transitionMatrix, 0, 0)


        return transitionMatrix

    def assignTransitionProb(self, heading, state, matrix):
        totalProb = 0.00
        if heading == "NORTH":
            x, y = state
            if self.isInMaze((x -1, y)):
                if self.isNotAnObstacle((x -1, y)):
                    matrix[x - 1][y] = 0.80
                else:
                    matrix[x - 1][y] = 0.00
                totalProb += matrix[x - 1][y]

            if self.isInMaze((x, y - 1)):
                if self.isNotAnObstacle((x, y - 1)):
                    matrix[x][y - 1] = 0.10
                else:
                    matrix[x][y - 1] = 0.00
                totalProb += matrix[x][y - 1]

            if self.isInMaze((x, y + 1)):
                if self.isNotAnObstacle((x, y + 1)):
                    matrix[x][y + 1] = 0.10  
                else:
                    matrix[x][y + 1] = 0.00
                totalProb += matrix[x][y + 1]

            # probability the robot bounced back to current position
            if totalProb < 1.00:
                matrix[x][y] = round(1.00 - totalProb, 2)

        elif heading == "WEST":
            x, y = state
            if self.isInMaze((x, y - 1)):
                if self.isNotAnObstacle((x, y - 1)):
                    matrix[x][y - 1] = 0.80
                else:
                    matrix[x][y - 1] = 0.00
                totalProb += matrix[x][y - 1]

            if self.isInMaze((x - 1, y)):
                if self.isNotAnObstacle((x - 1, y)):
                    matrix[x - 1][y] = 0.10
                else:
                    matrix[x - 1][y] = 0.00
                totalProb += matrix[x - 1][y]

            if self.isInMaze((x + 1, y)):
                if self.isNotAnObstacle((x + 1, y)):
                    matrix[x + 1][y] = 0.10  
                else:
                    matrix[x + 1][y] = 0.00
                totalProb += matrix[x + 1][y]

            # probability the robot bounced back to current position
            if totalProb < 1.00:
                matrix[x][y] = round(1.00 - totalProb, 2)

        else:
            #Other directions not implmented, only needed North and West. East and South would be same logic
            pass

    def isNotAnObstacle(self, coordinate):
        #Initialize cordinates for barriers 
        obstacles = [(1,5),(2,1),(2,4),(3,1),(3,4)]

        if coordinate in obstacles:
            return False
        
        return True

    def isInMaze(self, coordinate):
            x, y = coordinate
            #Checks to see if within the maze
            if (x >= 0 and x < 6) and (y >= 0 and y < 7):
                return True
            else:
                return False

    def representAsPerecentage(self, matrix, switch):
        if switch == True:
            for x in range(0, self.height):
                for y in range(0, self.width):
                    matrix[x][y] = matrix[x][y] * 100.00
        
        else:
             for x in range(0, self.height):
                for y in range(0, self.width):
                    matrix[x][y] = matrix[x][y] / 100.00

    def matrixFormatter(self, matrix):
        formattedMatrix = []

        for x in range(0, self.height):
            row = []
            for y in range(0, self.width):
                val = matrix[x][y]
                val = round(val, 2)  
                val = '{:.2f}'.format(round(val, 2))
                val = str(val) 
                val = val[0:4]
                row.append(val)
            formattedMatrix.append(row)

              
        return formattedMatrix

    def printMatrix(self, matrix):
        
        formattedMatrix = self.matrixFormatter(matrix)

        for row in formattedMatrix:
            print([state for state in row])
            print(" ")
        print("------------------------------------------------------------------\n")

class Robot:
    def __init__(self, hmmModel):
        self.hmm = hmmModel

    def senseLocation(self, perception):

        self.hmm.sensorUpdate(perception)
        print("Filtering After Evidence: {0}".format(perception))
        self.hmm.printGrid()
    
    def moveRobot(self, heading):

        self.hmm.motionUpdate(heading)
        print("Prediction After Action: {0}".format(heading))
        self.hmm.printGrid()

def main():
    HMM = HiddenMarkovModel()
    robot = Robot(HMM)

    #Robot sensing and order sequence
    robot.senseLocation(("0", "0", "0", "0"))
    robot.moveRobot("NORTH")

    robot.senseLocation(("1", "0", "0", "0"))
    robot.moveRobot("NORTH")

    robot.senseLocation(("1", "0", "0", "0"))
    robot.moveRobot("WEST")

    robot.senseLocation(("1", "0", "0", "0"))
    robot.moveRobot("NORTH")

    robot.senseLocation(("0", "0", "0", "0"))


if __name__ == "__main__":
    main()