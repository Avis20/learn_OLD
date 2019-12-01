package MyApp::Controller::Root;
use Moose;
use namespace::autoclean;
use uni::perl       qw| :dumper |;

BEGIN { extends 'Catalyst::Controller' }

__PACKAGE__->config(namespace => '');

sub monitor :Path('devel/monitor/player') :Args(0) {
    my ( $self, $c ) = @_;
    # warn dumper $c->req->headers();
    # warn "---" . $c->req->header('X-Player-Secret-Key');
    my $params = $c->req->params;
    $params->{'secret_key'} = $c->req->header('X-Player-Secret-Key');
    $params->{'device_key'} = $c->req->header('X-Player-Device-Key');
    $params->{'app_version'} = $c->req->header('X-Player-Version');
    warn "\n\n";
    warn dumper $params;
    warn "\n\n";

    my $rs = $c->model('TestDB')->resultset('Public::Monitor')->create($params);
    warn $rs;
    # warn dumper $rs->hash_api();

    $c->res->body(1);
}

sub index :Path :Args(0) {
    my ( $self, $c ) = @_;

    # Hello World
    $c->response->body( $c->welcome_message );
}

sub default :Path {
    my ( $self, $c ) = @_;
    $c->response->body( 'Page not found' );
    $c->response->status(404);
}

sub end : ActionClass('RenderView') {}

__PACKAGE__->meta->make_immutable;

1;
