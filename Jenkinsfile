pipeline {
    agent {
  label 'makec'
    stages{
        stage('get code') {
            steps{
                git branch: 'main', url: 'https://github.com/ganeshmerwade/git_rep.git'
            }
        }

        stage('check main') {
            steps{
                fileExists '/c/main.c'
                fileExists '/c/Makefile'
           }
        }

        stage('build') {
            steps{
                sh '''
                    make clean -f Makefile
                '''
            }
        }

        stage('test'){
            steps{
                sh 'echo "this is testing stage"'
            }
        }
        stage('save atrifact'){
            steps{
                sh 'scp -v -o StrictHostKeyChecking=no *.exe ubuntu@172.31.12.87:/home/ubuntu/cbuilds'
            }
        }
}
    }
}
