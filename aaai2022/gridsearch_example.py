from sklearn.datasets import load_iris
from sklearn.svm import SVC
from sklearn.model_selection import train_test_split

iris = load_iris()
# print(iris)
X_train, X_test, y_train, y_test = train_test_split(iris.data, iris.target, random_state=0)
print("Size of training set:{} size of testing set:{}".format(X_train.shape[0], X_test.shape[0]))

# grid search start
best_score = 0
for gamma in [0.001, 0.01, 0.1, 1, 10, 100] :
    for C in [0.001, 0.01, 0.1, 1, 10, 100] :
        svm = SVC(gamma=gamma, C=C) #对于每种参数可能的组合，进行一次训练
        svm.fit(X_train, y_train)
        score = svm.score(X_test, y_test)
        if score > best_score :
            best_score = score
            best_parameters = {'gamma': gamma, 'C':C}

# grid search end
print("Best score:{:.2f}".format(best_score))
print("Best parameters:{}".format(best_parameters))
