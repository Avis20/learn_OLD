from jenkins

user root

run mkdir ~/.gnupg && echo "disable-ipv6" >> ~/.gnupg/dirmngr.conf

run echo "deb http://apt.dockerproject.org/repo ubuntu-xenial main" \
         > /etc/apt/sources.list.d/docker.list \
        && apt-get update \
        && apt-cache policy docker-engine \
        && apt-get install -y apt-transport-https \
        && apt-get install -y sudo \
        && apt-get install -y --allow-unauthenticated docker-engine \
        && rm -rf /var/lib/apt/lists/*
run echo "jenkins ALL=NOPASSWD: ALL" >> /etc/sudoers

run curl -L https://github.com/docker/compose/releases/download/1.18.0/\
            docker-compose-`uname -s`-`uname -m` -o /usr/local/bin/docker-compose; \
            chmod +x /usr/local/bin/docker-compose

user jenkins
copy plugins.txt /usr/share/jenkins/plugins.txt
run /usr/local/bin/plugins.sh /usr/share/jenkins/plugins.txt
