#Git Gong
##GitHub Webhooks + Spark Core + Heroku
========

This project was inspired by the presence of Spark Cores in our office and the fact that GitHub has webhooks. Heroku proved to be the perfect glue to bring everything together.

###Instructions:

1. Get a Spark Core or Photon. Register, claim-your-device, & flash HelloWorld via wifi.
1. Connect your servo and calibrate - Play with angles to determine min/max - write down your angle setting when you encounter “servo-growling” so you can avoid that high-voltage state. Choose a generous angle range > 90° that has plenty of buffer between min and max. (eg: 30° - 160°) Here’s our quick-n-dirty spark code: https://github.com/caseprince/git-gong/blob/master/spark-gong.ino
1. Mount servo on silly rube-goldberg contraption w/ bell & clapper, keeping your angle range in mind.
1. Sign up for a free Heroku account and deploy something like this: https://github.com/caseprince/git-gong/blob/master/github-listener.rb
1. Test by hitting your Heroku URL. (eg: “sweet-gong-12345.herokuapp.com”)
1. Create a “Push event only” webhook on a GitHub repo pointing to your new Heroku app. (You’ll need admin privileges on the repo.) Test by pushing to your repo.
1. “Gong”
1. ???
1. Profit.

###Contraption in action:

https://www.youtube.com/watch?v=mpxQ4zg8YTM&feature=youtu.be

