# How to contribute to this project
## Initial Process
1. **Fork** the project. 
2. **Clone** the repo. 
```
git clone https://github.com/SamRB-dev/Kry0Steg.git
```
3. Determine what changes you are making and create a local branch. Make sure your branch name is meaningful. For instance, say you are working on a header file called "Ciphers.h" for the project. Then your branch name should be "/path/Cipher.h - <dev-name>". 
```
got checkout -b <branch-name>
```
4. Make changes on the code and Stage the changes. 
```
git add .
```
5. Commit the changes. 
```
git commit
```
or
```
git commit -m "<message>"
```
6. Push the changes. 
```
git push
```
7. Create a pull request. 

## Continuation Process
1. Switch to the main branch. 
```
git checkout main
```
2. Do a fresh pull to update the main repo. 
```
git pull
```
3. Switch to your working branch.
```
git checkout <branch-name>
```
### Repeat step 4 to 7 from initial process.
