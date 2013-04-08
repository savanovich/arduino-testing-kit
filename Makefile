HOME := /home/alexey/


.PHONY : deploy
deploy:
	-git add .
	-git commit -am "Updated" && git push && git push origin master
