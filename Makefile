.PHONY : deploy
deploy:
	-git add .
	-git commit -am "Updated" 
	git push origin master && git push bitucket master
