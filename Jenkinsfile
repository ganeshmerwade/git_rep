pipeline {
    agent {
  label 'makec'
    }
    stages{
        stage('get code') {
            steps{
                git branch: 'main', url: 'https://github.com/ganeshmerwade/git_rep.git'
            }
        }

        stage('check main') {
            steps{
                sh '''
                if (fileExists 'c/main.c) {
                        echo 'File exists'
                    } else {
                        echo 'File does not exist'
                #fileExists '/c/main.c'
                #fileExists '/c/Makefile'
                '''
           }
        }

        stage('build') {
            steps{
                sh '''
                    make
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
                sh 'scp -v -o StrictHostKeyChecking=no ABC.exe ubuntu@172.31.12.87:/home/ubuntu/cbuilds/'
            }
        }

}
}
