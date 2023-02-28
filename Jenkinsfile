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

        stage('check main and makefile') {
            steps{
                sh '''
                echo "$(pwd)"
                if [ -f main.c ] && [ -f Makefile ];then
                echo "required files exists"
                else
                echo "files does not exists"
                exit 1
                fi
             '''
           }
        }

        stage('build') {
            steps{
                sh '''
                    make clean
                    make
                '''
            }
        }

        stage('test'){
            steps{
                sh 'echo "this is testing stage"'
            }
        }
        stage('archive and save'){
            steps{
                archiveArtifacts artifacts: 'ABC.exe', followSymlinks: false
                sh 'scp -v -o StrictHostKeyChecking=no *.exe ubuntu@172.31.12.87:/home/ubuntu/cbuilds/ABC_$(date +%d_%m_%Y_%H_%M_%S).exe'
            }
        }

}
}
