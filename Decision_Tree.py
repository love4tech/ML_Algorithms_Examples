import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn import preprocessing
from sklearn import tree

data_url = 'http://mlr.cs.umass.edu/ml/machine-learning-databases/wine-quality/winequality-red.csv'
data = pd.read_csv(data_url, sep=';')

print(data.head(10))

import seaborn as sns
sns.factorplot(
    x='quality', 
    data=data, 
    kind='count'
).set_axis_labels('Quality', 'Count of such wines');

y = data.quality
X = data.drop('quality', axis=1)

X_train, X_test, y_train, y_test = train_test_split(X, y,test_size=0.3)

X_train_scaled = preprocessing.scale(X_train)
print (X_train_scaled)

# Using decision tree for the classification

clf=tree.DecisionTreeClassifier()
clf.fit(X_train, y_train)

y_pred = clf.predict(X_test)
print (y_pred)

ct=0
for i in range(len(y_test)):
    if(y_pred[i]==expected_y[i]):
        ct=ct+1
print ("Accuracy of the used model is " + str((ct/len(y_test))*100) + " %")
